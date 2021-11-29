#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "StringBuilder.h"

int main()
{
    char *g = "12345678\n90\n";
    fprintf(stdout, "%s, %lu\n", g, strlen(g));
    struct StringBuilder *temp = makeStringBuilder();
    FILE *f = fopen("log.txt", "w+");
    for(int i = 0; (unsigned long)i < strlen(g); i++)
    {
        addToStringBuilder(temp, g[i]);
        printNodes(temp, f);
    }
    char *test = stringFromStringBuilder(temp);
    fprintf(f, "test=\"%s\", %lu\n", test, strlen(test));
    fclose(f);
    free(test);
    freeStringBuilder(temp);
}
