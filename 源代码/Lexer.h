#pragma once
#include <string>
using std::string;
#include <vector>
using std::vector;


enum TK_type
{
	TK_integer,     //����
	TK_float,		//������
	Tk_negative_minus,	//���š�-��
	TK_positive_plus,	//���š�+��
	TK_plus,		//�Ӻ� +
	TK_minus,		//���� -
	TK_star,		//�˺� *
	TK_divide,		//���� /
	TK_mod,			//ȡ�� %
	TK_lbracket,	//�����ţ�
	TK_rbracket,	//������ )
	TK_equality,	//�Ⱥ� =
	TK_nagetive,	//���� -
	TK_positive,	//���� +
	TK_caret		//�˷� ^
};

class token
{
public:
	void set_index(TK_type);
	void set_text(string);
	TK_type get_type();
	string get_text();
private:
	TK_type type;		//token������
	string  text;		//token������
};

extern vector<token> Token;
void lexical_analysis();
void show_the_tokens();
