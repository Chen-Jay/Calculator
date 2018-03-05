#include "Lexer.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <sstream>
using std::stringstream;
vector<token> Token;

int count = 0;			//用于记录第几个token
void lexical_analysis()
{
	string expression;
	//cout << "please enter your legal expression." << endl;

	string buf;	cin >> buf; //用来缓存输入的整个式子

	string str_;			//用于缓存符号等
	bool if_str=false;		//用于判定是否是字符模式
	string int_ = "";		//用于缓存数字
	bool if_int = false;	//用于判定是否是整数模式
	string dou_ = "";		//用于缓存浮点数
	bool if_double=false;	//用于判定是否浮点模式
	
	
	
	
	for (int i = 0; i < buf.length(); i++)
	{
		if (buf[i]<='9'&&buf[i]>='0'&&if_double==false)	//整形的数字处理
		{
			if_int = true;
			int_ += buf[i];
		}

		else if (buf[i] <= '9'&&buf[i] >= '0'&&if_double == true)
		{
			dou_ += buf[i];
		}

		else if (buf[i] == '.')
		{
			if_int = false;
			if_double = true;
			dou_ = int_;
			dou_ += ".";
		}
		/*else if (
					(buf[i] == '-' ||buf[i] == '+' )&&
					(  i == 0 || (buf[i - 1] == '*' || buf[i - 1] == '/' || buf[i - 1] == '-' ||
						   	      buf[i - 1] == '+' || buf[i - 1] == '=' || buf[i - 1] == '(' )   )
				)						//当该符号为‘-’号且其前一位不是数字或“）”时，将其判定为负号
		{
			token operator_;
			if (buf[i] == '-')
			{
				operator_.set_index(TK_nagetive);
				operator_.set_text("-");
			}
			else if(buf[i] == '+')
			{
				operator_.set_index(TK_positive);
				operator_.set_text("+");
			}

			{
				Token.push_back(operator_);
				if_double = false;
				if_int = false;
				int_ = "";
				dou_ = "";
			}											//将整数，含小数型数判定初始化
		}*/
		else if (buf[i] == '*' || buf[i] == '/' || buf[i] == '-'||
				 buf[i] == '+' || buf[i] == '='	|| buf[i] =='('	||
				 buf[i] == ')' )		//遇到运算符号后，将之前的数字数据填入token。将符号填入后一个token
		{

			token operator_;							//用于换成数据的token类对象
			switch (buf[i])
			{
				case '*':
					operator_.set_index(TK_star);
					operator_.set_text("*");
					break;
				case '/':
					operator_.set_index(TK_divide);
					operator_.set_text("/");
					break;
				case '+':
					operator_.set_index(TK_positive_plus);
					operator_.set_text("+");
					break;
				case '-':
					operator_.set_index(Tk_negative_minus);
					operator_.set_text("-");
					break;
				case '=':
					operator_.set_index(TK_equality);
					operator_.set_text("=");
					break;
				case '(':
					operator_.set_index(TK_lbracket);
					operator_.set_text("(");
					break;
				case ')':
					operator_.set_index(TK_rbracket);
					operator_.set_text(")");
					break;
				default:
					break;
			}					//

			if (if_int==true)
			{
				//stringstream ss;						//用于类型与字符串之间的转换
				//ss << int_;
				token integer_;							//用与缓存数据的token类对象
				integer_.set_index(TK_integer);			//将该token的类型定为整形
				integer_.set_text(int_);			//将该token的内容用string的形式储存
				Token.push_back(integer_);				//将对象填入Token数组
			}
			if (if_double == true)
			{
				//stringstream ss;						//用于类型与字符串之间的转换
				//ss << dou_;								//用与缓存数据的token类对象
				token double_;							
				double_.set_index(TK_float);			//将该token的类型定为含小数型
				double_.set_text(dou_);				//将该token的内容用string的形式储存
				Token.push_back(double_);					//将对象填入Token数组
			}

			{
				Token.push_back(operator_);
				if_double = false;							
				if_int = false;
				int_ = "";
				dou_ = "";
			}											//将整数，含小数型数判定初始化
			
		}
	}
}

void show_the_tokens()
{
	cout << "these are the texts:" << endl;
	for (int i = 0; i < Token.size(); i++)
	{
		cout << Token[i].get_text()<<" ";
	}
	cout << endl;

	cout <<endl << "these are the types:" << endl;
	for (int i = 0; i < Token.size(); i++)
	{
		if (Token[i].get_type() == TK_divide)
		{
			cout << "divide ";
		}
		else if (Token[i].get_type() == TK_equality)
		{
			cout << "equality ";
		}
		else if (Token[i].get_type() == TK_float)
		{
			cout << "float ";
		}
		else if (Token[i].get_type() ==TK_integer)
		{
			cout << "integer ";
		}
		else if (Token[i].get_type() == TK_lbracket)
		{
			cout << "lbracket ";
		}
		else if (Token[i].get_type() == Tk_negative_minus)
		{
			cout << "negative-minus ";
		}
		else if (Token[i].get_type() == TK_mod)
		{
			cout << "mod ";
		}
		else if (Token[i].get_type() == TK_positive_plus)
		{
			cout << "positive-plus ";
		}
		else if (Token[i].get_type() == TK_rbracket)
		{
			cout << "rbracket ";
		}
		else if (Token[i].get_type() == TK_star)
		{
			cout << "star ";
		}
		else if (Token[i].get_type() == TK_nagetive)
		{
			cout << "nagetive ";
		}
		else if (Token[i].get_type() == TK_positive)
		{
			cout << "positive ";
		}
		else
		{
			cout << "something error!";
		}
	}
	cout << endl<<endl;
}


void token::set_index(TK_type tp)
{
	type = tp;
	return;
}

void token::set_text(string st)
{
	text = st;
	return;
}

TK_type token::get_type()
{
	return type;
}

string token::get_text()
{
	return text;
}
