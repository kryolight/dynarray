#include <stdio.h>

#include "dynarray.h"

#define NUM_TEST_ELEMENTS 32

int main(int argc, char** argv) {

  struct dynarray* da = dynarray_create();

  for (int i = 0; i < NUM_TEST_ELEMENTS; i++) {
    dynarray_insert(da, -1, i * 2);
  }

  printf("== Dynamic array contents: ");
  for (int i = 0; i < dynarray_size(da); i++) {
    printf("%4d ", dynarray_get(da, i));
  }
  printf("\n");

}
