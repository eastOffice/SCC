#include "scc.h"

void dynarray_realloc(Dynarray *parr, int new_size){
	int capacity;
	void *data;

	capacity = parr->capacity;
	while(capacity < new_size)
		capacity *= 2;
	data = realloc(parr->data, capacity);
	if(!data)
		error("OVERFLOW!");
	parr->capacity = capacity;
	parr->data = data;
}

void dynarray_add(Dynarray * parr, void *data){
	int count;
	count = parr->count + 1;
	if(count*sizeof(void *) > parr->capacity)
		dynarray_realloc(parr, count*sizeof(void *));
	parr->data[count-1] = data;
	parr->count = count;
}

void dynarray_init(Dynarray *parr, int initsize){
	if(parr){
		parr->data = (void**)malloc(sizeof(char)*initsize);
		parr->count = 0;
		parr->capacity = initsize;
	}
}

void dynarray_free(Dynarray *parr){
	void **p;
	for(p = parr->data; parr->count; ++p, --parr->count){
		if(*p)
			free(*p);
	}
	free(parr->data);
	parr->data = NULL;
}

void dynarray_search(Dynarray *parr, int key){
	int i;
	int **p;
	p = (int **)parr->data;
	for(i = 0; i<parr->count; p++)
		if(key == **p)
			return i;
	return -1;
}








