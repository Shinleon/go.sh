#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "StringBuilder.h"

int main()
{
    char *g = "1234567890";
    char *h = "hello world!";
    FILE *f = fopen("log.txt", "w+");  // open file
    if (f == NULL)
    {
        fprintf(stderr, "Failed to open file.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(f, "%s, %lu\n", g, strlen(g));
    fprintf(f, "%s, %lu\n", h, strlen(h));

    struct StringBuilder *temp = makeStringBuilder();  // allocate string builder

    int i = 0;
    for(; (unsigned long)i < strlen(g); i++)
    {
        addToStringBuilder(temp, g[i]);
        printNodes(temp, f);
    }
    char *test = flushStringBuilder(temp);
    fprintf(f, "test=\"%s\", %lu\n", test, strlen(test));
    free(test);

    for(i = 0; (unsigned long)i < strlen(h); i++)
    {
        addToStringBuilder(temp, h[i]);
        printNodes(temp, f);
    }
    test = flushStringBuilder(temp);
    fprintf(f, "test=\"%s\", %lu\n", test, strlen(test));
    free(test);

    freeStringBuilder(temp);  // deallocate stringBuilder
    fclose(f);  // close file
}
