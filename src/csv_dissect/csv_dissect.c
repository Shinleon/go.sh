#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "csv_dissect.h"
#include "../StringBuilder/StringBuilder.h"

struct CSVFileReader *makeCSVFileReader(const char *file, int headers, int load)
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
  makeCSVFileReader(f_name, 0, 0);

  return 0;
}
