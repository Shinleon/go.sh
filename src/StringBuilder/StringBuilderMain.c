#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "StringBuilder.h"

int main()
{
    char* g = "12345678\n90\n";
    fprintf(stdout, "%s, %lu\n", g, strlen(g));
    struct StringBuilder *temp = makeStringBuilder();
    for(int i = 0; (unsigned long)i < strlen(g); i++)
    {
        addToStringBuilder(temp, g[i]);
        printNodes(temp, stdout);
    }
    char *test = stringFromStringBuilder(temp);
    fprintf(stdout, "test=\"%s\", %lu\n", test, strlen(test));
    free(test);
    freeStringBuilder(temp);
}
