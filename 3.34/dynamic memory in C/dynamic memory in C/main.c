#include <stdio.h> // printf function is here
#include <stdlib.h> // functions for memory allocation are here


int main() {
	int* p = malloc(sizeof(int));	// malloc returns a void*. with a c++ compiler 
									// and explicit cast from the void* to the 
									// assigned type is needed. It is not required
									// in a c file (with c compiler).

									// malloc only allocates memory and does not 
									// initialize it.
	if (p == NULL) {
		printf("failed to allocated memeory \n");
		return -1;
	}

	*p = 5;
	printf("%d\n", *p);
	free(p);						// after this point p is pointing to an invalid
									// memory location; dangling pointer so:
	p = NULL;

	p = calloc(3, sizeof(int));		// calloc initializes to zero and can be used 
									// for allocating a memory array.
	if (p == NULL) {
		printf("failed to allocated memeory \n");
		return -1;
	}
	*p = 10;
	printf("%d\n", *p);
	free(p);
	p = NULL;

	p = malloc(4 * sizeof(int));	// same as calloc(3,sizeof(int)) without memory
									// initialization to 0

	p = realloc(p, 10 * sizeof(int));
	if (p == NULL) {
		printf("failed to allocated memeory \n");
		return -1;
	}

	free(p);
	p = NULL;
	return 0;
}