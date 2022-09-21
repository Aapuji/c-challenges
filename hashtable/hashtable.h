// Hash Table Implementation in C
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

typedef struct _hash_node {
    char *key;
    int value;
    struct _hash_node *next;
} _hash_node;

typedef struct hashtable {
    const size_t capacity;
    _hash_node **buckets;
} hashtable;

unsigned long hash(unsigned char *str);

hashtable hash_factory(size_t capacity);

/**
 * Returns 0 if malloc failed,
 * otherwise returns the length of linked list after it is put
*/
size_t put(hashtable *tbl, char *key, int value);

int get(hashtable *tbl, char *key);

/**
 * Returns length of array (# of keys)
*/
size_t keys(hashtable *tbl, char **arr, size_t length);

/**
 * Returns length of array (# of values)
*/
size_t values(hashtable *tbl, int *arr, size_t length);

void hash_free(hashtable *tbl);

#endif
