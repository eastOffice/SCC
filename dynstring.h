#include <stdio.h>
typedef struct DynString
{
    int		count;		// �ַ�������
	int		capacity;	// �������ַ����Ļ���������
    char	*data;		// ָ���ַ�����ָ��
} DynString;

void dynstring_realloc(DynString *cstr, int new_size);
void dynstring_chcat(DynString *cstr, int ch);
void dynstring_reset(DynString *cstr);
