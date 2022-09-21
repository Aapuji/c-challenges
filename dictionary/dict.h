#ifndef DICT_H
#define DICT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    int value;
} item;

typedef struct {
    item *items;
    int length;
} dict;

dict *dict_factory(char *string, int value);

void define(dict *d, char *key, int value);

void undefine(dict *d, char *key);

int get(dict *d, char *key);

void keys(dict *d, char **arr);

#endif
