
#ifndef STRINGARRAYLIST_H
#define STRINGARRAYLIST_H

struct StringArrayList
{
    char **data;
    enum Allocation *status;
    unsigned int len;
    unsigned int alloc_quant;
};

enum Allocation
{
    STAL_STACK = 1,
    STAL_UNKOWN = 0,
    STAL_HEAP = -1,
};

struct StringArrayList* makeStringArrayList(unsigned int initial_len);

void freeStringArrayList(struct StringArrayList *sal);

int sizeOfStringArrayList(struct StringArrayList *sal);

char* getFromStringArrayList(struct StringArrayList *sal, int index);

void appendToStringArrayList(
    struct StringArrayList *sal, char *item, enum Allocation status);

void printStringArrayList(struct StringArrayList *sal, FILE *out);

#endif