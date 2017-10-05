#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "dynarray.h"

#define DYNARRAY_INIT_CAPACITY 4

struct dynarray {
  int* data;
  int size;
  int capacity;
};

struct dynarray* dynarray_create(int capacity) {

  assert(capacity > 0);
  struct dynarray* da = malloc(sizeof(struct dynarray));
  assert(da);

  da->data = malloc(capacity * sizeof(int));
  assert(da->data);
  da->size = 0;
  da->capacity = capacity;

  return da;

}

void dynarray_free(struct dynarray* da) {

  assert(da);
  free(da->data);
  free(da);

}

int dynarray_size(struct dynarray* da) {

  assert(da);
  return da->size;

}

int dynarray_get(struct dynarray* da, int idx) {

  assert(da);
  assert((idx < da->size && idx >= 0) || idx == -1);

  // Let users specify idx = -1 to indicate the end of the array.
  if (idx == -1) {
    idx = da->size - 1;
  }

  return da->data[idx];

}

void dynarray_set(struct dynarray* da, int idx, int val) {

  assert(da);
  assert((idx < da->size && idx >= 0) || idx == -1);

  // Let users specify idx = -1 to indicate the end of the array.
  if (idx == -1) {
    idx = da->size - 1;
  }

  da->data[idx] = val;

}

void _dynarray_resize(struct dynarray* da, int new_capacity) {

  assert(new_capacity > da->size);

}

void dynarray_insert(struct dynarray* da, int idx, int val) {

  assert(da);
  assert((idx < da->size && idx >= 0) || idx == -1);

}

void dynarray_remove(struct dynarray* da, int idx) {

  assert(da);
  assert((idx < da->size && idx >= 0) || idx == -1);

  // Let users specify idx = -1 to indicate the end of the array.
  if (idx == -1) {
    idx = da->size - 1;
  }

}
