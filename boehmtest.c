#include <assert.h>
#include <stdio.h>
#include <gc.h>

/*
	boemtest.c
	Andrew Pennebaker
	1 Mac 2011

	From Wikipedia.
	http://en.wikipedia.org/wiki/Boehm_garbage_collector#Example

	Requires Boem GC
	http://www.hpl.hp.com/personal/Hans_Boehm/gc/
*/

int main(void) {
	int i;

	GC_INIT();

	for (i = 0; i < 10000000; i++) {
		int **p = GC_MALLOC(sizeof(int *));
		int *q = GC_MALLOC_ATOMIC(sizeof(int));

		assert(*p == 0);
		*p = GC_REALLOC(q, 2 * sizeof(int));

		if (i % 100000 == 0) {
			printf("Heap size = %zu\n", GC_get_heap_size());
		}
	}
}