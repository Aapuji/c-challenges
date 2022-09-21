#include <stdio.h>
#include "vector.h"

// Just some code to show it's working
int main() {
    int arr[] = {1, 2, 3};
    vector m = vector_factory(arr, sizeof(arr));
    for (int i = 0; i < m.length; i++) {
        printf("%i\n", m.values[i]);
    }
    printf("\n");
    push(&m, 4);
    for (int i = 0; i < m.length; i++) {
        printf("%i\n", m.values[i]);
    }
    printf("\n");
    push(&m, 5);
    for (int i = 0; i < m.length; i++) {
        printf("%i\n", m.values[i]);
    }
    printf("\n");
   
    printf("%i\n\n", pop(&m));
    for (int i = 0; i < m.length; i++) {
        printf("%i\n", m.values[i]);
    }
    printf("\n");
   
    insert(&m, 2, 5);
    for (int i = 0; i < m.length; i++) {
        printf("%i\n", m.values[i]);
    }
    printf("\n");
   
    free(m.values);
   
    return 0;
}
