#include <stdio.h>
#include <windows.h>

//DynString
typedef struct DynString
{
	int count;
	int capacity;
	char *data;
} DynString;

void dynstring_realloc(DynString *cstr, int new_size); //动态字符串重新分配
void dynstring_chcat(DynString *cstr, int ch);//拼接
void dynstring_reset(DynString *cstr);//重置

//DynArray
typedef struct DynArray
{
	int count;
	int capacity;
	void **data;
} DynArray;

void dynarray_add(DynArray *parr, void *data);
void dynarray_init(DynArray *parr,int initsize);
void dynarray_free(DynArray *parr);                 
int dynarray_search(DynArray *parr, int key);

//lex，枚举token编码
enum e_TokenCode
{  
	
	TK_PLUS,		// + 
    TK_MINUS,		// - 
    TK_STAR,		// *
    TK_DIVIDE,		// / 
    TK_MOD,			// % 
    TK_EQ,			// == 
    TK_NEQ,			// != 
    TK_LT,			// < 
    TK_LEQ,			// <= 
    TK_GT,			// > 
    TK_GEQ,			// >= 
    TK_ASSIGN,		// = ¸
    TK_POINTSTO,	// -> 
    TK_DOT,			// . 
	TK_AND,         // & 
	TK_OPENPA,		// ( 
	TK_CLOSEPA,		// ) 
	TK_OPENBR,		// [ 
	TK_CLOSEBR,		// ]
	TK_BEGIN,		// { 
	TK_END,			// } 
    TK_SEMICOLON,	// ;   
    TK_COMMA,		// ,
	TK_ELLIPSIS,	// ... 
	TK_EOF,			// 


    TK_CINT,		// constant int
    TK_CCHAR,		// constant char
    TK_CSTR,		// constant string

    //keywords
	KW_CHAR,		// char
	KW_SHORT,		// short
	KW_INT,			// int
    KW_VOID,		// void 
    KW_STRUCT,		// struct 
	KW_IF,			// if
	KW_ELSE,		// else
	KW_FOR,			// for
	KW_CONTINUE,	// continue
    KW_BREAK,		// break 
    KW_RETURN,		// return
    KW_SIZEOF,		// sizeof

    KW_ALIGN,		// __align	
    KW_CDECL,		// __cdecl
	KW_STDCALL,     // __stdcall
	

	TK_IDENT        //标识符
};

enum e_LexState
{
	LEX_NORMAL,
	LEX_SEP
};

typedef struct TkWord
{
	int tkcode;
	struct Tkword *next;
	char *spelling;
	struct Symbol *sym_struct;
	struct Symbol *sym_identifier;
	
}TkWord;

#define MAXKEY 1024

extern TkWord* tk_hashtable[MAXKEY];
extern DynArray tktable;
#define CH_EOF	(-1)

TkWord* tkword_direct_insert(TkWord* tp);
TkWord* tkword_insert(char *p);
int is_nodigit(char c);
int is_digit(char c);
void getch();
void parse_num();
void parse_string(char sep);
void parse_comment();
void get_token();
char *get_tkstr(int v);
void init_lex();
void test_lex();
void color_token(int lex_state);

//error
enum e_ErrorLevel
{
	LEVEL_WARNING,
	LEVEL_ERROR
};

enum e_WorkStage
{
	STAGE_COMPILE,
	STAGE_LINK
};

void warning(char *fmt, ...);
void error(char *fmt, ...);
void expect(char *msg);
void skip(int c);
void link_error(char *fmt, ...);

//scc
extern DynString tkstr;
extern FILE *fin;
extern char ch;
extern char *filename;
extern int token;
extern int tkvalue;
extern int line_num;
int elf_hash(char *name);
void *mallocz(int size);




