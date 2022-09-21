#include <stdio.h>
#include "linked-list.h"

int main(void) {
    linked ll = linked_factory(1);
    append(&ll, 2);
    append(&ll, 3);
    append(&ll, 4);
    append(&ll, 5);
   
    // printf("%i", ll.head.next->next->next->value);
    // printf("%i", node_at(&ll, 1)->value);
    for (int i = 0; i < ll.length; i++) {
        printf("%i\n", value_at(&ll, i));
    }
   
    printf("\n");
    printf("%i\n", pop(&ll));
   
    printf("\n");
    for (int i = 0; i < ll.length; i++) {
        printf("%i\n", value_at(&ll, i));
    }
   
    int *arr = malloc(0);
    to_array(&ll, arr);
    printf("\n");
    for (int i = 0; i < ll.length; i++) {
        printf("%i\n", arr[i]);
    }
   
    printf("\n");
    insert(&ll, 2, 5);
    for (int i = 0; i < ll.length; i++) {
        printf("%i\n", value_at(&ll, i));
    }
   
    linked_destructor(&ll); // Does this work? Idk
   
    return 0;
}
