#include <stdlib.h>
#include <stdio.h>

#include "StringArrayList.h"

int main()
{
    char *g = malloc(sizeof(char) * 11);
    for (int i = 0; i < 11; i++)
    {
        if (i == 10)
        {
            g[i] = '\0';
        }
        else
        {
            g[i] = 'a';
        }
    }
    struct StringArrayList *t = makeStringArrayList(0);
    printStringArrayList(t, stdout);
    for (int i = 1; i <= 18; i++)
    {
        appendToStringArrayList(t, "hello", STAL_HEAP);
    }
    appendToStringArrayList(t, g, STAL_STACK);
    printStringArrayList(t, stdout);
    fprintf(stdout, "Testing get, String @%d, \"%s\"\n", sizeOfStringArrayList(t) - 1, getFromStringArrayList(t, sizeOfStringArrayList(t) - 1));
    freeStringArrayList(t);
}
