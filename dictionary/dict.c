#include "dict.h"

typedef struct {
    char *key;
    int value;
} item;

typedef struct {
    item *items;
    int length;
} dict;

dict *dict_factory(char *string, int value) {
    dict *d = malloc(sizeof(dict));
    if (d == NULL) exit(1);
   
    d->items = malloc(sizeof(item));
    if (d == NULL) exit(1);
   
    d->items[0].key = string;
    d->items[0].value = value;
    d->length = 1;
    return d;
}

void define(dict *d, char *key, int value) {
    for (int i = 0; i < d->length; i++) {
        if (strcmp(d->items[i].key, key) == 0) {
            d->items[i].value = value;
            return;
        }
       
    }
   
    item *i = realloc(d->items, sizeof(item) * (d->length + 1));
    if (i == NULL) exit(1);
   
    d->items = i;
    d->items[d->length].key = key;
    d->items[d->length].value = value;
    printf("KEY: \"%s\", VALUE: %i\n", d->items[d->length].key, d->items[d->length].value);
   
    d->length++;
}

void undefine(dict *d, char *key) {
    int i = 0;
    for (; i < d->length; i++) {
        if (strcmp(d->items[i].key, key) == 0){
            goto key_exists;
        };
    }
   
    printf("Dictionary Error: key \"%s\" does not exist in dictionary.", key);
    exit(1);
   
    key_exists:
        for (; i < d->length - 1; i++) {
            d->items[i] = d->items[i+1];
        }
        item *new_items = realloc(d->items, (d->length - 1) * sizeof(item));
        if (new_items == NULL) exit(1);
       
        d->items = new_items;
        d->length--;
}

int get(dict *d, char *key) {
    for (int i = 0; i < d->length; i++) {
        if (strcmp(d->items[i].key, key) == 0) {
            return d->items[i].value;
        }
       
    }
   
    printf("Dictionary Error: Key \"%s\" does not exist.", key);
    exit(1);
}

void keys(dict *d, char **arr) {
    if  (sizeof(*arr) < sizeof(char *) * d->length) {
        printf("Dictionary Error: Ouput array size is too small for keys, and could not be resized");
        exit(1);
    }
    for (int i = 0; i < d->length; i++) {
        arr[i] = d->items[i].key;
    }
}
