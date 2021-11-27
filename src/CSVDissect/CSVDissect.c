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

struct CSVFileReader *makeCSVFileReader(
  const char *file, int headers, char quoteChar, enum CSVQuotingStyle style)
{
  struct CSVFileReader *ret = malloc(sizeof(struct CSVFileReader));
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
  char* temp = stringFromStringBuilder(t);
  fprintf(stdout, "%s", temp);
  free(temp);
  freeStringBuilder(t);
  return ret;
}

int main(void)
{
  const char *f_name = "../../nav_data/directory_alias.csv";
  makeCSVFileReader(f_name, 0, '|', QUOTE_MINIMAL);

  return 0;
}
