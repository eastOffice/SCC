#include "scc.h"

FILE *fin = NULL;
char *filename;
char *outfile;

/***********************************************************
 * ����:	������ڴ沢�����ݳ�ʼ��Ϊ'0'
 * size: �����ڴ��С
 **********************************************************/
void *mallocz(int size)
{
    void *ptr;
	ptr = malloc(size);
	if (!ptr && size)
        error("OVERFLOW");
    memset(ptr, 0, size);
    return ptr;
}

/***********************************************************
 * ����:	�����ϣ��ַ
 * key:��ϣ�ؼ���(Ϊ���뱾����SC���Թؼ������ֿ����˴����ǳ�Ϊ��ϣ�ؼ���)
 * MAXKEY:��ϣ����
 **********************************************************/
int elf_hash(char *key)
{
    int h = 0, g;
    while (*key)
	{
        h = (h << 4) + *key++;
        g = h & 0xf0000000;
        if (g)
            h ^= g >> 24;
        h &= ~g;
    }
    return h % MAXKEY;
}

/***********************************************************
 * ����:	��ʼ��
 **********************************************************/
void init ()
{
	line_num = 1;
    init_lex();
}


/***********************************************************
 * ����:	ɨβ������
 **********************************************************/
void cleanup()
{
	int i;
	for(i = TK_IDENT; i < tktable.count; i++)
	{
        free(tktable.data[i]);
	}
    free(tktable.data);
}

/***********************************************************
 * ����:	�õ��ļ���չ��
 * fname:	�ļ�����
 **********************************************************/
char *get_file_ext(char *fname)
{
	char *p;
	p = strrchr(fname,'.');
	return p+1;
}

/***********************************************************
 * ����:	main������
 **********************************************************/
int main(int argc, char ** argv)
{

	fin = fopen("HelloWorld.c","rb");
	if(!fin)
	{
		printf("Cannot Open!\n");
		return 0;
	}
	init();
	getch();
	test_lex();
	cleanup();
	fclose(fin);
	printf("Scanning succeeded!");
	return 0;
}
