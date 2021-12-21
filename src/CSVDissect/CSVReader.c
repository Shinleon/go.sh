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

char *stringFromFile(const char *file)
{
  FILE *csv_file = fopen(file, "r+");
  if (csv_file == NULL)
  {
    perror("Error opening file"); // print error
    return NULL;
  }

  char c;
  struct StringBuilder *t = makeStringBuilder();
  do
  {
    c = fgetc(csv_file); // get next char
    if (feof(csv_file))  // test for eof
    {
      break;
    }
    addToStringBuilder(t, c);
  } while (1);

  fclose(csv_file);

  char *ret = stringFromStringBuilder(t);
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
  ret->delim = delimiter;
  ret->qchar = quoteChar;
  return ret;
}

char *nextLine_temp(struct CSVReader *reader)
{
  struct StringBuilder *temp = makeStringBuilder();
  char c = '\0';
  int in_quote = 0;
  while (!(feof(reader->f)))
  {
    // 1) if we find
    c = fgetc(reader->f); // get next char
    if (c == '\r')
    { // check for carriage return (CRLF style returns)
      c = fgetc(reader->f);
      if (c == '\n')
      {
        break; // "\r\n" induces a next line behavior
      }
      else
      {
        // I'm not sure if you can have a '\r' in the middle of a csv...
        //  It's behavior is to jump back to the beginning of the line, so
        //  for now we'll just ignore it and not print it to the file ??
      }
    }
    else if (c == '\n')
    {
      break;
    }
    else
    { // we have a valid char, should go inside the stringBuilder
      if (c == reader->delim)
      {
        // check if we're inside a quote,
        //  if we are, ignore it, otherwise, trigger a StringBuilder flush/reset
      }
      else if (c == reader->qchar)
      {
        // check if we're inside a quote,
        //  if we are, end the quote and get rid of trailing delimiter,
        //    basically like the "\r\n" fiasco. Also, set in_quote to 0
        //  if we're not, we need to make sure nothing is currently in the
        //    string builder and then start adding to it, after setting in_quote to 1
      }
      addToStringBuilder(temp, c);
    }
  }
  if (feof(reader->f)) // if we are at the end of the file, return a NULL
  {
    return NULL;
  } // Otherwise, return the fields as an array (for now a string)
  char *ret = stringFromStringBuilder(temp);
  freeStringBuilder(temp);
  return ret;
}

int main(void)
{
  const char *f_name = "../../nav_data/directory_alias.csv";
  struct CSVReader *reader = makeCSVReader(f_name, ',', '|');
  char *x = nextLine_temp(reader);
  while (x != NULL)
  {
    fprintf(stdout, "%s\n", x);
    free(x);
    x = nextLine_temp(reader);
  }
  fprintf(stdout, ">>> end >>>\n");
  fprintf(stdout, "%c\n", '\\');
  return 0;
}
