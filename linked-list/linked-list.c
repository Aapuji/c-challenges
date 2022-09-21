#include "linked-list.h"

linked linked_factory(int value) {
    node *n = malloc(sizeof(node));
    n->value = value;
    n->next = NULL;
   
    linked ll = {.head = *n, .length = 1};
    return ll;
}

node *node_at(linked *list, int index) {
    node *current = &list->head;
    int i = 0;
    while (i < index) {
        current = current->next;
        i++;
    }
    return current;
}

int value_at(linked *list, int index) {
    return node_at(list, index)->value;
}

void append(linked *list, int value) {
    node *current = &list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = malloc(sizeof(node));
    current->next->value = value;
    current->next->next = NULL;
    list->length++;
}

int pop(linked *list) {
    node *second_last = node_at(list, list->length - 2);
    int result = second_last->next->value;
    free(second_last->next);
    list->length--;
    return result;
}

void to_array(linked *list, int *src) {
    src = realloc(src, list->length * sizeof(int));
    if (src == NULL) exit(1);
   
    for (int i = 0; i < list->length; i++) {
        src[i] = value_at(list, i);
    }
}

void insert(linked *list, int index, int value) {
    if (index > list->length - 1) {
        printf("Index Error: Index out of range");
        exit(1);
    }
   
    if (index == 0) {
        node *n = malloc(sizeof(node));
        n->value = list->head.value;
        n->next = list->head.next;
       
        node head = { .value = value, .next = n };
        list->head = head;
    } else {
        node *prev = node_at(list, index-1);
        node *n = malloc(sizeof(node));
        n->value = value;
        n->next = prev->next;
        prev->next = n;
    }
   
    list->length++;
}

void linked_destructor(linked *list) {
    for (int i = list->length-1; i > 0; i--) {
        free(node_at(list, i));
    }
}
