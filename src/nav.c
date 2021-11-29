#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>  // https://stackoverflow.com/a/4204758
                     // https://faq.cprogramming.com/cgi-bin/smartfaq.cgi?answer=1046380353&id=1044780608
#include <unistd.h>  // https://stackoverflow.com/a/298518

// https://en.wikipedia.org/wiki/Damerau–Levenshtein_distance

// https://datatracker.ietf.org/doc/html/rfc4180#ref-4  definition of csv 
// extra csv info V-V below V~V
// https://www.cloudbakers.com/blog/everything-you-didnt-want-to-have-to-know-about-csv

// look here for something interesting on c and typing(?)
// https://softwareengineering.stackexchange.com/questions/117024/why-was-the-c-syntax-for-arrays-pointers-and-functions-designed-this-way

// look into fseek, ftell; maybe can speed up search by creating some
// auxillary data file and organizing the csv?

// look into errno so we can always tell what kind of errors are happening

// zeroth argument is the compiled .out file
// first argument is the csv location

int main(int argc, char *argv[])
{
  char* csv_loc = argv[1];
  
  char* buf = getcwd(NULL, 0);
  fprintf(stdout, "current directory is %s\n", buf);
  free(buf);
  fprintf(stdout, "csv is located @ '%s'\n", csv_loc);

  for (int i = 2; i < argc; i++)
  {
    fprintf(stdout, "other argument #%d, '%s'\n", i, argv[i]);
  }
  return(0);
}

void directoryWalk()
{
  DIR *d;
  struct dirent *dir;
  d = opendir(".");
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  }
}

void inputExample(){

  char str [80];
  int i = 79;

  fputs("Enter your family name: ", stdout);
  fgets(str, i, stdin);  // get a string of length i (keep one position for eol char)
  str[strcspn(str, "\n")] = 0; // find the first instance of '\n' and set it to eol char
  fprintf(stdout, "You said: %s;\n", str);
}
