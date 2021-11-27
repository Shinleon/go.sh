#ifndef STRINGBUILDER_H
#define STRINGBUILDER_H

struct StringBuilder
{
    struct StringNode* head;
    struct StringNode* tail;
    int length;
};

struct StringBuilder* makeStringBuilder();

char* stringFromStringBuilder(struct StringBuilder*);

struct StringBuilder* addToStringBuilder(struct StringBuilder*, char);

void freeStringBuilder(struct StringBuilder*);

#endif
