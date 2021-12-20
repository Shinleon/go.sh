#ifndef STRINGBUILDER_H
#define STRINGBUILDER_H

struct StringBuilder
{
    struct StringNode* head;
    struct StringNode* tail;
    unsigned int length;
};

struct StringBuilder* makeStringBuilder();

char* stringFromStringBuilder(struct StringBuilder*);

struct StringBuilder* addToStringBuilder(struct StringBuilder*, char);

char* flushStringBuilder(struct StringBuilder* sb);

char getLastChar(struct StringBuilder* sb);

void printNodes(struct StringBuilder* sb, FILE *f);

void freeStringBuilder(struct StringBuilder*);

#endif
