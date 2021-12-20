#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "StringBuilder.h"

struct StringNode
{
    char val;
    struct StringNode* next;
};

struct StringNode* makeStringNode(char c, struct StringNode* next) {
    struct StringNode* ret = malloc(sizeof(struct StringNode));
    ret->val = c;
    ret->next = next;
    return ret;
}

struct StringNode* freeStringNode(struct StringNode* n) {
    if (n == NULL)
    {
        return NULL;
    }
    struct StringNode* t = n->next;
    free(n);
    return t;
}

struct StringBuilder* makeStringBuilder() {
    struct StringBuilder* ret = malloc(sizeof(struct StringBuilder));
    ret->head = NULL;
    ret->tail = NULL;
    ret->length = 0;
    return ret;
}

void resetStringBuilder(struct StringBuilder* sb) {
    sb->head = NULL;
    sb->tail = NULL;
    sb->length = 0;
}

char* stringFromStringBuilder(struct StringBuilder* sb)
{
    if(sb == NULL)
    {
        return NULL;
    }
    char *ret = malloc(sizeof(char)*(sb->length + 1));
    if (ret == NULL)
    {
        fprintf(stderr, "ERROR, couldn't malloc for char* creation in StringBuilder: %s.\n",
        strerror(errno));
        
    }
    struct StringNode* t = sb->head;
    unsigned int i = 0;
    for(; i < sb->length; i++)
    {
        ret[i] = t->val;
        t = t->next;
    }
    ret[i] = 0;
    return ret;
}

struct StringBuilder* addToStringBuilder(struct StringBuilder* sb, char c)
{
    if(sb == NULL) {
        return NULL;
    }
    struct StringNode* t = sb->tail;
    if(t == NULL) { //this is only the case if there is nothing
        sb->head = makeStringNode(c, NULL);
        sb->tail = sb->head;
    }
    else {
        sb->tail->next = makeStringNode(c, NULL);
        sb->tail = sb->tail->next;
    }
    sb->length += 1;
    return sb;
}

char getLastChar(struct StringBuilder* sb) {
    return sb->tail->val;
}

char* flushStringBuilder(struct StringBuilder* sb) {
    char *ret = stringFromStringBuilder(sb);
    while (sb->head) {
        sb->head = freeStringNode(sb->head);
    }
    sb->tail = NULL;
    sb->length = 0;
    return ret;
}

void printNodes(struct StringBuilder *sb, FILE *f) {
    struct StringNode* t = sb->head;
    int i = 0;
    while(t != sb->tail)
    {
        fprintf(f, "{#:%d=%c}->", i, t->val);
        ++i;
        t = t->next;
    }
    fprintf(f, "\\\n");
}

void freeStringBuilder(struct StringBuilder* sb)
{
    struct StringNode* t = sb->head;
    while (t)
    {
        t = freeStringNode(t);
    }
    resetStringBuilder(sb);
    free(sb);
}
