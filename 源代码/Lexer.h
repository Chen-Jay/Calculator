#pragma once
#include <string>
using std::string;
#include <vector>
using std::vector;


enum TK_type
{
	TK_integer,     //整数
	TK_float,		//浮点数
	Tk_negative_minus,	//符号“-”
	TK_positive_plus,	//符号“+”
	TK_plus,		//加号 +
	TK_minus,		//减号 -
	TK_star,		//乘号 *
	TK_divide,		//除号 /
	TK_mod,			//取余 %
	TK_lbracket,	//左括号（
	TK_rbracket,	//右括号 )
	TK_equality,	//等号 =
	TK_nagetive,	//负号 -
	TK_positive,	//正号 +
	TK_caret		//乘方 ^
};

class token
{
public:
	void set_index(TK_type);
	void set_text(string);
	TK_type get_type();
	string get_text();
private:
	TK_type type;		//token的类型
	string  text;		//token的内容
};

extern vector<token> Token;
void lexical_analysis();
void show_the_tokens();
