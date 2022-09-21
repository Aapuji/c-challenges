#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node;

typedef struct {
    node head;
    int length;
} linked;

linked linked_factory(int value);

node *node_at(linked *list, int index);

int value_at(linked *list, int index);

void append(linked *list, int value);

int pop(linked *list);

void to_array(linked *list, int *src);

void insert(linked *list, int index, int value);

void linked_destructor(linked *list);

#endif
