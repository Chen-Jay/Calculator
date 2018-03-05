#pragma once
#include <vector>
using std::vector;
#include "Lexer.h"  

enum Data_type
{
	compute_sign,		//运算符号
	int_double,			//小数
	power,				//乘方数
	fraction,			//分数
};

enum Sign
{
	negative,	//负号
	positive,	//正号
	plus,		//加号
	minus,		//减号
	star,		//乘号
	divide,		//除号
	left,		//左括号
	right,		//右括号
	caret,		//乘方
	equal,		//等号
};

class Data
{
public:
	Data(Data_type, double, double);
	Data(Data_type, Sign);
	Data(Data_type, double);
	Data();
	void set_data_type(Data_type);
	Data_type get_data_type();
	void set_first_data(double);
	double get_first_data();
	void set_second_data(double);
	double get_second_data();
	void set_sign(Sign);
	Sign get_sign();
	void set_priority(int);
	int get_priority();
	string get_sign_text();
	void operator= (Data &a);
private:
	Data_type type;
	Sign sign;
	double first_data;			//底数，分母，小数
	double second_data;			//指数，分子，
	int priority;				//优先级
	

};

extern vector<Data> Data_Array;
bool if_negetive(token now, token last);
bool if_positive(token now, token last);
bool if_negetive(token now);
bool if_positive(token now);
void parse();
void show_the_expression();
