#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "CSVReader.h"
#include "../StringBuilder/StringBuilder.h"

// create a CSV_StringReader 
// look at csv.QUOTE_MINIMAL in https://docs.python.org/3/library/csv.html
//  different CSV settings require different things; also the quote char isn't always
//  the quotation symbol. 

char* stringFromFile(const char *file)
{
  FILE *csv_file = fopen(file, "r+");
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

struct CSVReader *makeCSVReader(const char *file, char delimiter, char quoteChar)
{
  struct CSVReader *ret = malloc(sizeof(struct CSVReader));
  FILE *csv_file = fopen(file, "r");
  if (csv_file == NULL)
  {
    perror("Error opening file"); // print error
    return NULL;
  }
  ret->f = csv_file;
  return ret;
}

char* nextLine(struct CSVReader* reader, FILE* log) {
  struct StringBuilder* temp = makeStringBuilder();
  char c = '\0';
  while (!(feof(reader->f))) {
    c = fgetc(reader->f); // get next char
    if (c == '\n' || c=='\r') // test for eof or newline
    {
      break;
    }
    else {
      if (c=='\n' || c == '\r')
      {
        fprintf(log, "wtf");
      }
      addToStringBuilder(temp, c);
      printNodes(temp, log);
    }
  } 
  fprintf(stdout, "The value of c is %d, length = %d\n", c, temp->length);
  char* ret = stringFromStringBuilder(temp);
  setvbuf(stdout, NULL, _IOLBF, 0);
  fprintf(stdout, "%s", ret);
  free(temp);
  return ret;
}

int main(void)
{
  const char *f_name = "../../nav_data/directory_alias.csv";
  struct CSVReader *reader = makeCSVReader(f_name, ',', '|');
  FILE* log = fopen("./log.txt", "w+");
  char *x = NULL;
  do {
    x = nextLine(reader, log);
    fprintf(log, "\">%s<\", %lu", x, strlen(x));
  } while(x != NULL && strlen(x) != 0);
  free(x);
  fprintf(stdout, ">>> end >>>");
  return 0;
}
