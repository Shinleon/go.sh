#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>  // https://stackoverflow.com/a/4204758
                     // https://faq.cprogramming.com/cgi-bin/smartfaq.cgi?answer=1046380353&id=1044780608

// https://en.wikipedia.org/wiki/Damerau–Levenshtein_distance

int main(int argc, char *argv[])
{
  char str [80];
  int i = 79;

  fputs("Enter your family name: ", stdout);
  fgets(str, i, stdin);  // get a string of length i (keep one position for eol char)
  str[strcspn(str, "\n")] = 0; // find the first instance of '\n' and set it to eol char
  fprintf(stdout, "You said: %s; %d, %s\n", str, argc, argv[0]);

  for (int i = 0; i < argc; i++)
  {
    fprintf(stdout, "%d, %s\n", i, argv[i]);
  }

  DIR *d;
  struct dirent *dir;
  d = opendir(".");
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  }
  return(0);
}
