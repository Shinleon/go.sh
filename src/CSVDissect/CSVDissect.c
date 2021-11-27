#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "CSVDissect.h"
#include "../StringBuilder/StringBuilder.h"

// create a CSV_StringReader 
// look at csv.QUOTE_MINIMAL in https://docs.python.org/3/library/csv.html
//  different CSV settings require different things; also the quote char isn't always
//  the quotation symbol. 

char* stringFromFile(const char *file)
{
  FILE *csv_file = fopen(file, "r");
  if (csv_file == NULL)
  {
    perror("Error opening file"); // print error
    return NULL;
  }

  char c; struct StringBuilder* t = makeStringBuilder();

  do
  {
    c = fgetc(csv_file); // get next char
    if (feof(csv_file)) // test for eof
    {
      break;
    }
    addToStringBuilder(t, c);
  } while (1);

  fclose(csv_file);

  char* ret = stringFromStringBuilder(t);
  freeStringBuilder(t);

  return ret;
}

struct CSVFileReader *makeCSVFileReader(
  const char *file, char quoteChar)
{
  struct CSVFileReader *ret = malloc(sizeof(struct CSVFileReader));
  
  char* temp = stringFromFile(file);
  fprintf(stdout, "%s", temp);
  free(temp);
  return ret;
}

int main(void)
{
  const char *f_name = "../../nav_data/directory_alias.csv";
  makeCSVFileReader(f_name, '|');

  return 0;
}
