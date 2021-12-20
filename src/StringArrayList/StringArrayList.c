#include <stdlib.h>
#include <stdio.h>

#include "StringArrayList.h"

struct StringArrayList *makeStringArrayList(unsigned int initial_len)
{
    initial_len = initial_len == 0 ? 16 : initial_len;
    struct StringArrayList *ret = malloc(sizeof(struct StringArrayList));
    char **temp_chars = malloc(sizeof(char *) * initial_len);
    enum Allocation *temp_alloc = malloc(sizeof(enum Allocation) * initial_len);
    ret->data = temp_chars;
    ret->status = temp_alloc;
    ret->len = 0;
    ret->alloc_quant = initial_len;
    return ret;
}

int sizeOfStringArrayList(struct StringArrayList* sal) {
    return sal->len;
}

char* getFromStringArrayList(struct StringArrayList* sal, int index) {
    if (index < 0 || index > sal->len) {
        return NULL;
    }
    return sal->data[index];
}

void freeAllocated(struct StringArrayList *sal)
{
    for (int i = 0; i < sal->alloc_quant; i++)
    {
        if (sal->status[i] == STAL_STACK)
        {
            free(sal->data[i]);
        }
    }
}

void freeStringArrayList(struct StringArrayList *sal)
{
    freeAllocated(sal);
    free(sal->data);
    free(sal->status);
    free(sal);
}

void extendStringArrayList(struct StringArrayList *sal, unsigned int mult)
{
    mult = mult < 2 ? 2 : mult;
    int next_alloc = sal->alloc_quant * mult;
    char **next_data = realloc(sal->data, sizeof(char *) * next_alloc);
    if (next_data == NULL)
    {
        fprintf(stderr, "ERROR: malloc of size %d failed.", next_alloc);
        exit(EXIT_FAILURE);
    }
    enum Allocation *next_status = realloc(sal->status, sizeof(enum Allocation) * next_alloc);
    if (next_data == NULL)
    {
        fprintf(stderr, "ERROR: malloc of size %d failed.", next_alloc);
        exit(EXIT_FAILURE);
    }
    sal->data = next_data;
    sal->status = next_status;
    sal->alloc_quant = next_alloc;
}


void appendToStringArrayList(
    struct StringArrayList *sal, char *item, enum Allocation status)
{
    if(sal->len+1 > sal->alloc_quant)
    {
        extendStringArrayList(sal, 0);
    }
    sal->data[sal->len] = item;
    sal->status[sal->len] = status;
    sal->len++;
}

void resetStringArrayList(struct StringArrayList *sal)
{
    sal->len = 0;
    freeAllocated(sal);
}

void printStringArrayList(struct StringArrayList *sal, FILE *out)
{
    fprintf(out, "Allocation Size: %u, Length used: %u\n", sal->alloc_quant, sal->len);
    for(unsigned int i = 0; i < sal->len; i++)
    {
        fprintf(out, "String @%u \"%s\", allocation status: %s\n", 
            i, sal->data[i], sal->status[i] == STAL_STACK ? "Stack" : sal->status[i] == STAL_HEAP ? "Heap" : "Unknown");
    }
}
