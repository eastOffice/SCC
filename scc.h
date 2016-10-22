#include <stdio.h>
#include <windows.h>
#include "dynarray.h"
#include "dynstring.h"
#include "lex.h"


extern DynString tkstr;
extern FILE *fin;
extern char ch;
extern char *filename;
extern int token;
extern int tkvalue;
extern int line_num;
int elf_hash(char *name);
void *mallocz(int size);

