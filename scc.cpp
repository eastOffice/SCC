#include "scc.h"

FILE *fin = NULL;
char *filename;
char *outfile;

void *mallocz(int size){
	void *ptr;
	ptr = malloc(size);
	if(!ptr && size)
		err("error");
	memset(ptr, 0, size);
	return ptr;
}

int elf_hash(char *key){
	int h = 0, g;
	while(*key){
		h = (h<<4) + *key++;
		g = h & 0xf0000000;
		if(g)
			h ^= g>>24;
		h &= ~g;
	}
	return h%MAXKEY;
}

void init(){
	line_num = 1;
	init_lex();
}

void cleanup()
{
	int i;
	for(i = TK_IDENT; i < tktable.count; i++)
	{	
        free(tktable.data[i]);
	}
    free(tktable.data);
}

char *get_file_ext(char *fname)
{
	char *p;
	p = strrchr(fname,'.');
	return p+1;
}

int main(int argc, char ** argv)
{  	

	fin = fopen(argv[1],"rb");
	if(!fin)
	{
		printf("Cannot open!\n"); 
		return 0;
	}
	init();
	getch();
	test_lex();
	cleanup();
	fclose(fin);
	printf("%s Scanning succeed!",argv[1]);
	return 1;
}












