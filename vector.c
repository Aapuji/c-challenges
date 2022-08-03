#include "vector.h"

vector vector_factory(int arr[], int size) {
    vector m = {
        .values = malloc(size),
        .length = size / sizeof(int)
    };
    if (m.values == NULL) exit(1);
   
    for (int i = 0; i < size / sizeof(int); i++) {
        m.values[i] = arr[i];
    }
    return m;
}

void push(vector *vector, int value) {
    int *m = realloc(vector->values, (vector->length + 1) * sizeof(int));
    if (m == NULL) exit(1);
   
    m[vector->length] = value;
    vector->values = m;
    vector->length++;
}

int pop(vector *vector) {
    int value = vector->values[vector->length - 1];
    int *m = realloc(vector->values, (vector->length - 1) * sizeof(int));
   
    if (m == NULL) exit(1);
   
    vector->values = m;
    vector->length--;
    return value;
}

void insert(vector *vector, int index, int value) {
    if (index < 0 || index > vector->length - 1) exit(2);
   
    int *m = realloc(vector->values, (vector->length + 1) * sizeof(int));
    if (m == NULL) exit(1);
   
    for (int i = vector->length; i > index; i--) {
        m[i] = vector->values[i-1];
    }
    m[index] = value;
    vector->values = m;
    vector->length++;
}
