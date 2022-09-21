#include <stdio.h>
#include "hashtable.h"

int main(void) {
    hashtable table = hash_factory(100);
    printf("%lu\n", table.capacity);
    put(&table, "Zero", 0);
    printf("%i\n", get(&table, "Zero"));
   
    put(&table, "Identity", 1);
    printf("%i\n", get(&table, "Identity"));
    put(&table, "Binary", 2);
    printf("%i\n", get(&table, "Binary"));
    put(&table, "Decimal", 1);
    put(&table, "Negative", -1);
   
    printf("%i\n", get(&table, "Decimal"));
    printf("%i\n", get(&table, "Negative"));
   
    put(&table, "Decimal", 10);
    printf("%i\n", get(&table, "Decimal"));
   
    int size = 10;
    char **arr = malloc(sizeof(char *) * size);
    size_t len = keys(&table, arr, size);
    printf("KEYSLEN: %lu\n", len);
    for (int i = 0; i < len; i++) {
        printf("\t%s\n", arr[i]);
    }
   
    int *vals = malloc(sizeof(int) * size);
    size_t val_len = values(&table, vals, size);
    printf("VALSLEN: %lu\n", val_len);
    for (int i = 0; i < val_len; i++) {
        printf("\t%i\n", vals[i]);
    }
   
    hash_free(&table);

    return 0;
}
