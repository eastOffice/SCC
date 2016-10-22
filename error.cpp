#include "scc.h"

/*
stage: 编译阶段 or 链接阶段
level： 错误级别
fmt： 参数输出格式
ap: 可变参数列表
*/
void handle_exception(int stage,int level,char *fmt,va_list ap)
{
	char buf[1024];
	vsprintf(buf, fmt, ap);
	if(stage == STAGE_COMPILE)
	{
		if(level == LEVEL_WARNING)
			printf("%s(line %d): Compile Warning :%s!\n",filename, line_num, buf);
		else
		{
			printf("%s(line %d): Compile Error :%s!\n",filename, line_num, buf);
			exit(-1);
		}
	}
	else
	{
		printf("Link Error : %s!\n", buf);
		exit(-1);
	}
}

void warning(char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    handle_exception(STAGE_COMPILE,LEVEL_WARNING, fmt, ap);
    va_end(ap);
}

void error(char *fmt, ...)
{
	va_list ap;
    va_start(ap, fmt);
    handle_exception(STAGE_COMPILE,LEVEL_ERROR, fmt, ap);
    va_end(ap);
}

void expect(char *msg){
	error("Lack%s", msg);
}

void skip(int v){
	if(token != v)
		error("Lack '%s'", get_tkstr(v));
	get_token();
}

void link_error(char *fmt, ...)
{
	va_list ap;
    va_start(ap, fmt);
    handle_exception(STAGE_LINK,LEVEL_ERROR, fmt, ap);
    va_end(ap);
}




