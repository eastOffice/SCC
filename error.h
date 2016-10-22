#include "scc.h"
#include <stdio.h>
#include <windows.h>
enum e_ErrorLevel
{
	LEVEL_WARNING,
	LEVEL_ERROR,
};

/* ¹¤×÷½×¶Î */
enum e_WorkStage
{
	STAGE_COMPILE,
	STAGE_LINK,
};
void warning(char *fmt, ...);
void error(char *fmt, ...);
void expect(char *msg);
void skip(int c);
void link_error(char *fmt, ...);
