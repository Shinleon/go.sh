#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  char str [80];
  int i;

  printf ("Enter your family name: ");
  scanf ("%79s",str); 
  printf("you said: %s\n", str);
}
