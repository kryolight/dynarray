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

struct dynarray* dynarray_create() {

  struct dynarray* da = malloc(sizeof(struct dynarray));
  assert(da);

  da->data = malloc(DYNARRAY_INIT_CAPACITY * sizeof(int));
  assert(da->data);
  da->size = 0;
  da->capacity = DYNARRAY_INIT_CAPACITY;

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

/*
 * Auxilliary function to perform a resize on the underlying array.
 */
void _dynarray_resize(struct dynarray* da, int new_capacity) {

  assert(new_capacity > da->size);

  /*
   * Allocate space for the new array.
   */
  int* new_data = malloc(new_capacity * sizeof(int));
  assert(new_data);

  /*
   * Copy data from the old array to the new one.
   */
  for (int i = 0; i < da->size; i++) {
    new_data[i] = da->data[i];
  }

  /*
   * Put the new array into the dynarray struct.
   */
  free(da->data);
  da->data = new_data;
  da->capacity = new_capacity;

}

void dynarray_insert(struct dynarray* da, int idx, int val) {

  assert(da);
  assert((idx < da->size && idx >= 0) || idx == -1);

  // Let users specify idx = -1 to indicate the end of the array.
  if (idx == -1) {
    idx = da->size;
  }

  /*
   * Make sure we have enough space for the new element.
   */
  if (da->size == da->capacity) {
    printf("== Increasing DA capacity to %d\n", 2 * da->capacity);
    _dynarray_resize(da, 2 * da->capacity);
  }

  /*
   * Move all elements behind the new one back one index to make space
   * for the new one.
   */
  for (int i = da->size; i > idx; i--) {
    da->data[i] = da->data[i-1];
  }

  /*
   * Put the new element into the array.
   */
  da->data[idx] = val;
  da->size++;

}

void dynarray_remove(struct dynarray* da, int idx) {

  assert(da);
  assert((idx < da->size && idx >= 0) || idx == -1);

  // Let users specify idx = -1 to indicate the end of the array.
  if (idx == -1) {
    idx = da->size - 1;
  }

  /*
   * Move all elements behind the one being removed forward one index,
   * overwriting the element to be removed in the process.
   */
  for (int i = idx; i < da->size - 1; i++) {
    da->data[i] = da->data[i+1];
  }

  da->size--;

}
