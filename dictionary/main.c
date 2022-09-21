#include <stdio.h>
#include "dict.h"

int main() {
    dict *d = dict_factory("Unit", 1);
    define(d, "Identity", 0);
    define(d, "Even", 2);
    define(d, "Negative", -1);
    define(d, "Ten", 5);
   
    printf("%i\n", get(d, "Ten"));
    define(d, "Ten", 10);
    printf("%i\n", get(d, "Ten"));
   
    undefine(d, "Ten");
    // printf("%i\n", get(d, "Ten"));
   
    char *ks[4];
    keys(d, ks);
    for (int i = 0; i < d->length; i++) {
        printf("\t%i\n", ks[i]);
    }
   
    return 0;
}
