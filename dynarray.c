#include "dynarray.h"

/***********************************************************
 *  ����:		���·��䶯̬��������
 *  parr:		��̬����ָ��
 *  new_size:	��̬��������Ԫ�ظ���
 **********************************************************/
void dynarray_realloc(DynArray *parr, int new_size)
{
    int capacity;
    void *data;

    capacity = parr->capacity;
    while (capacity < new_size)
        capacity = capacity * 2;
    data = realloc(parr->data, capacity);
    if (!data)
        error("OVERFLOW");
    parr->capacity = capacity;
    parr->data = data;
}

/***********************************************************
 *  ����:	׷�Ӷ�̬����Ԫ��
 *  parr:	��̬����ָ��
 *  data:	��Ҫ׷�ӵ���Ԫ��
 **********************************************************/
void dynarray_add(DynArray *parr, void *data)
{
 	int count;
    count = parr->count + 1;
    if (count*sizeof(void*) > parr->capacity)
        dynarray_realloc(parr, count*sizeof(void*));
    parr->data[count - 1] = data;
    parr->count = count;
}

/***********************************************************
 * ����:		��ʼ����̬���鴢������
 * parr:		��̬����ָ��
 * initsize:	��̬�����ʼ������ռ�
 **********************************************************/
void dynarray_init(DynArray *parr, int initsize)
{
	if(parr != NULL)
	{
		parr->data = (void**)malloc(sizeof(void*)*initsize);
		parr->count = 0;
		parr->capacity = initsize;
	}
}

/***********************************************************
 * ����:	ɾ����̬�����е�i��Ԫ��
 * parr:	��̬����ָ��
 * i:		�ڲ���Ԫ��
 **********************************************************/
void dynarray_delete(DynArray *parr,int i)
{
	if(parr->data[i])
		free(parr->data[i]);
    memcpy(parr->data+i,parr->data+i+1,sizeof(void*)*(parr->count-i-1));
    free(parr->data);
    parr->data = NULL;
}

/***********************************************************
 *  ����:	�ͷŶ�̬����ʹ�õ��ڴ�ռ�
 *  parr:	��̬����ָ��
 **********************************************************/
void dynarray_free(DynArray *parr)
{
    void **p;
    for (p = parr->data; parr->count; ++p, --parr->count)
        if (*p)
            free(*p);
    free(parr->data);
    parr->data = NULL;
}

/***********************************************************
 *  ����:	��̬����Ԫ�ز���
 *  parr:	��̬����ָ��
 *  key:	Ҫ���ҵ�Ԫ��
 **********************************************************/
int dynarray_search(DynArray *parr, int key)
{
    int i;
   	int **p;
	p = (int**)parr->data;
    for (i = 0; i < parr->count; ++i, p++)
    if (key == **p)
        return i;
    return -1;
}
