all: test_dynarray

test_dynarray: dynarray.o test_dynarray.c
	gcc --std=c99 -g test_dynarray.c dynarray.o -o test_dynarray

dynarray.o: dynarray.c dynarray.h
	gcc --std=c99 -g -c dynarray.c

clean:
	rm -f dynarray.o test_dynarray
