#include <stdio.h>
typedef struct DynArray
{
    int count;			// ��̬����Ԫ�ظ���
    int capacity;		// ��̬���黺�������ȶ�
    void **data;		// ָ������ָ������
} DynArray;

void dynarray_add(DynArray *parr, void *data);
void dynarray_init(DynArray *parr,int initsize);
void dynarray_free(DynArray *parr);
int dynarray_search(DynArray *parr, int key);
