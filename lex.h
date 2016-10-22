
/* 单词编码 */
enum e_TokenCode
{
	/* 运算符及分隔符 */
	TK_PLUS,		// + 加号
    TK_MINUS,		// - 减号
    TK_STAR,		// * 星号
    TK_DIVIDE,		// / 除号
    TK_MOD,			// % 求余运算符
    TK_EQ,			// == 等于号
    TK_NEQ,			// != 不等于号
    TK_LT,			// < 小于号
    TK_LEQ,			// <= 小于等于号
    TK_GT,			// > 大于号
    TK_GEQ,			// >= 大于等于号
    TK_ASSIGN,		// = 赋值运算符
    TK_POINTSTO,	// -> 指向结构体成员运算符
    TK_DOT,			// . 结构体成员运算符
	TK_AND,         // & 地址与运算符
	TK_OPENPA,		// ( 左圆括号
	TK_CLOSEPA,		// ) 右圆括号
	TK_OPENBR,		// [ 左中括号
	TK_CLOSEBR,		// ] 右圆括号
	TK_BEGIN,		// { 左大括号
	TK_END,			// } 右大括号
    TK_SEMICOLON,	// ; 分号
    TK_COMMA,		// , 逗号
	TK_ELLIPSIS,	// ... 省略号
	TK_EOF,			// 文件结束符

    /* 常量 */
    TK_CINT,		// 整型常量
    TK_CCHAR,		// 字符常量
    TK_CSTR,		// 字符串常量

	/* 关键字 */
	KW_CHAR,		// char关键字
	KW_SHORT,		// short关键字
	KW_INT,			// int关键字
    KW_VOID,		// void关键字
    KW_STRUCT,		// struct关键字
	KW_IF,			// if关键字
	KW_ELSE,		// else关键字
	KW_FOR,			// for关键字
	KW_CONTINUE,	// continue关键字
    KW_BREAK,		// break关键字
    KW_RETURN,		// return关键字
    KW_SIZEOF,		// sizeof关键字

    KW_ALIGN,		// __align关键字
    KW_CDECL,		// __cdecl关键字 standard c call
	KW_STDCALL,     // __stdcall关键字 pascal c call

	/* 标识符 */
	TK_IDENT
};

/* 词法状态 */
enum e_LexState
{
	LEX_NORMAL,
	LEX_SEP
};

/* 单词存储结构定义 */
typedef struct TkWord
{
    int  tkcode;					// 单词编码
    struct TkWord *next;			// 指向哈希冲突的其它单词
    char *spelling;					// 单词字符串
	struct Symbol *sym_struct;		// 指向单词所表示的结构定义
    struct Symbol *sym_identifier;	// 指向单词所表示的标识符
} TkWord;

#define MAXKEY	1024				// 哈希表容量

extern TkWord* tk_hashtable[MAXKEY];// 单词哈希表
extern DynArray tktable;			// 单词动态数组
#define CH_EOF   (-1)				// 文件尾标识


TkWord* tkword_direct_insert(TkWord* tp);
TkWord* tkword_insert(char * p);
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
