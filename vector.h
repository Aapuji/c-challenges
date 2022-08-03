#ifndef VECTOR
#define VECTOR

#include <stdlib.h>

typedef struct {
    int *values;
    int length;
} vector;

vector vector_factory(int arr[], int size);
void push(vector *vector, int value);
int pop(vector *vector);
void insert(vector *vector, int index, int value);

#endif
