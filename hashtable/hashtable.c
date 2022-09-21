#include "hashtable.h"

unsigned long hash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;
    while (c = *str++) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

hashtable hash_factory(size_t capacity) {
    _hash_node **buckets = malloc(sizeof(_hash_node *) * capacity);
    for (size_t i = 0; i < capacity; i++) {
        buckets[i] = NULL;
    }
    hashtable t = {
        .capacity = capacity,
        .buckets = buckets
    };
    return t;
}

/**
 * Returns 0 if malloc failed,
 * otherwise returns the length of linked list after it is put
*/
size_t put(hashtable *tbl, char *key, int value) {
    size_t index = hash(key) % tbl->capacity;
    if (!tbl->buckets[index]) {
        _hash_node *n = malloc(sizeof(_hash_node));
        if (n == NULL) return 0;
       
        n->key = key;
        n->value = value;
        n->next = NULL;
        tbl->buckets[index] = n;
        return 1;
    }
   
    _hash_node *tmp = tbl->buckets[index];
    size_t i = 1;
    bool found_key = false;
    do {
        if (strcmp(tmp->key, key) == 0) {
            tmp->value = value;
            found_key = true;
        }
        if (!found_key) tmp = tmp->next;
        i++;
    } while (tmp->next != NULL);
    if (found_key) return i;
   
    _hash_node *n = malloc(sizeof(_hash_node));
    if (n == NULL) return 0;
   
    n->key = key;
    n->value = value;
    n->next = NULL;
    tmp->next = n;
   
    return i;
}

int get(hashtable *tbl, char *key) {
    size_t index = hash(key) % tbl->capacity;
    _hash_node *tmp = tbl->buckets[index];
    do {
        if (strcmp(tmp->key, key) == 0) {
            return tmp->value;
        }
    } while (tmp->next != NULL);
   
    exit(1);
}

/**
 * Returns length of array (# of keys)
*/
size_t keys(hashtable *tbl, char **arr, size_t length) {
    _hash_node *ptr = NULL;
   
    size_t i = 0;
    size_t pos = 0;
    for (; i < tbl->capacity; i++) {
        if (tbl->buckets[i] == NULL) continue;
       
        ptr = tbl->buckets[i];
        do {
            if (length <= pos) {
                printf("Memory Error: Target array does not have enough memory");
                exit(1);
            }
           
            arr[pos] = ptr->key;
            pos++;
        } while (ptr->next != NULL);
    }
   
    return pos;
}

/**
 * Returns length of array (# of values)
*/
size_t values(hashtable *tbl, int *arr, size_t length) {
    _hash_node *ptr = NULL;
   
    size_t i = 0;
    size_t pos = 0;
    for (; i < tbl->capacity; i++) {
        if (tbl->buckets[i] == NULL) continue;
       
        ptr = tbl->buckets[i];
        do {
            if (length <= pos) {
                printf("Memory Error: Target array does not have enough memory");
                exit(1);
            }
           
            arr[pos] = ptr->value;
            pos++;
        } while (ptr->next != NULL);
    }
   
    return pos;
}

void hash_free(hashtable *tbl) {
    for (size_t i = 0; i < tbl->capacity; i++) {
        if (tbl->buckets[i] == NULL) continue;
       
        _hash_node *ptr = tbl->buckets[i];
        _hash_node *next = NULL;
        while (ptr->next != NULL) {
            next = ptr->next;
            free(ptr);
            ptr = next;
        }
        free(ptr);
    }
}
