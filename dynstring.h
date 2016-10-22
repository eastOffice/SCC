#include <stdio.h>
typedef struct DynString
{
    int		count;		// 字符串长度
	int		capacity;	// 包含该字符串的缓冲区长度
    char	*data;		// 指向字符串的指针
} DynString;

void dynstring_realloc(DynString *cstr, int new_size);
void dynstring_chcat(DynString *cstr, int ch);
void dynstring_reset(DynString *cstr);
