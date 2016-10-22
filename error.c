#include "error.h"


/***********************************************************
 * ����:	�쳣����
 * stage:	����׶λ������ӽ׶�
 * level:	���󼶱�
 * fmt:		��������ĸ�ʽ
 * ap:		�ɱ�����б�
 **********************************************************/
void handle_exception(int stage,int level,char *fmt,va_list ap)
{
	char buf[1024];
	vsprintf(buf,fmt,ap);
	if(stage == STAGE_COMPILE)
	{
		if(level==LEVEL_WARNING)
			printf("%s(line %d): Compile warning: %s!\n",filename,line_num,buf);
		else
		{
			printf("%s(line %d): Compile error:\n",filename,line_num,buf);
			exit(-1);
		}
	}
	else
	{
		printf("Link error:%s!\n",buf);
		exit(-1);
	}
}

/***********************************************************
 * ����:	���뾯�洦��
 * fmt:		��������ĸ�ʽ
 **********************************************************/
void warning(char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    handle_exception(STAGE_COMPILE,LEVEL_WARNING, fmt, ap);
    va_end(ap);
}

/***********************************************************
 * ����:	��������������
 * fmt:		��������ĸ�ʽ
 **********************************************************/
void error(char *fmt, ...)
{
	va_list ap;
    va_start(ap, fmt);
    handle_exception(STAGE_COMPILE,LEVEL_ERROR, fmt, ap);
    va_end(ap);
}

/***********************************************************
 * ����:	��ʾ���󣬴˴���Ҫȱ��ĳ���﷨�ɷ�
 * msg:		��Ҫʲô�﷨�ɷ�
 **********************************************************/
void expect(char *msg)
{
    error("Lack%s", msg);
}

/***********************************************************
 * ����:	��������v,ȡ��һ����,�����ǰ���ʲ���v,��ʾ����
 * v:		���ʱ��
 **********************************************************/
void skip(int v)
{
    if (token != v)
       error("Lack'%s'", get_tkstr(v));
    get_token();
}

/***********************************************************
 * ����:	���Ӵ�����
 * fmt:		��������ĸ�ʽ
 **********************************************************/
void link_error(char *fmt, ...)
{
	va_list ap;
    va_start(ap, fmt);
    handle_exception(STAGE_LINK,LEVEL_ERROR, fmt, ap);
    va_end(ap);
}
