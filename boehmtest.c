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

  Splint annotations by Guillermo
  http://stackoverflow.com/questions/6903272#6904955
*/

/*@shared@*/ /*@null@*/ /*@out@*/ static void * SPLINT_GC_MALLOC(size_t size) /*@*/ {
  /*@-onlytrans@*/
  return GC_MALLOC(size);
  /*@=onlytrans@*/
}

/*@shared@*/ /*@null@*/ /*@out@*/ static void * SPLINT_GC_MALLOC_ATOMIC(size_t size) /*@*/ {
  /*@-onlytrans@*/
  return GC_MALLOC_ATOMIC(size);
  /*@=onlytrans@*/
}

/*@shared@*/ /*@null@*/ /*@out@*/ static void * SPLINT_GC_REALLOC(void *ptr, size_t size) /*@*/ {
  /*@-onlytrans@*/
  return GC_REALLOC(ptr, size);
  /*@=onlytrans@*/
}

int main(void) {
  int i;

  GC_INIT();

  for (i = 0; i < 10000000; i++) {
    int **p = SPLINT_GC_MALLOC(sizeof(int *));
    int *q = SPLINT_GC_MALLOC_ATOMIC(sizeof(int));

    if (p != NULL && q != NULL) {
      assert(*p == 0);
      *p = SPLINT_GC_REALLOC(q, 2 * sizeof(int));

      if (i % 100000 == 0) {
        printf("Heap size = %u\n", (unsigned int) GC_get_heap_size());
      }
    }
  }

  return 0;
}
