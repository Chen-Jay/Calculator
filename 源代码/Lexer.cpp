#include "Lexer.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <sstream>
using std::stringstream;
vector<token> Token;

int count = 0;			//���ڼ�¼�ڼ���token
void lexical_analysis()
{
	string expression;
	//cout << "please enter your legal expression." << endl;

	string buf;	cin >> buf; //�����������������ʽ��

	string str_;			//���ڻ�����ŵ�
	bool if_str=false;		//�����ж��Ƿ����ַ�ģʽ
	string int_ = "";		//���ڻ�������
	bool if_int = false;	//�����ж��Ƿ�������ģʽ
	string dou_ = "";		//���ڻ��渡����
	bool if_double=false;	//�����ж��Ƿ񸡵�ģʽ
	
	
	
	
	for (int i = 0; i < buf.length(); i++)
	{
		if (buf[i]<='9'&&buf[i]>='0'&&if_double==false)	//���ε����ִ���
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
				)						//���÷���Ϊ��-��������ǰһλ�������ֻ򡰣���ʱ�������ж�Ϊ����
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
			}											//����������С�������ж���ʼ��
		}*/
		else if (buf[i] == '*' || buf[i] == '/' || buf[i] == '-'||
				 buf[i] == '+' || buf[i] == '='	|| buf[i] =='('	||
				 buf[i] == ')' )		//����������ź󣬽�֮ǰ��������������token�������������һ��token
		{

			token operator_;							//���ڻ������ݵ�token�����
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
				//stringstream ss;						//�����������ַ���֮���ת��
				//ss << int_;
				token integer_;							//���뻺�����ݵ�token�����
				integer_.set_index(TK_integer);			//����token�����Ͷ�Ϊ����
				integer_.set_text(int_);			//����token��������string����ʽ����
				Token.push_back(integer_);				//����������Token����
			}
			if (if_double == true)
			{
				//stringstream ss;						//�����������ַ���֮���ת��
				//ss << dou_;								//���뻺�����ݵ�token�����
				token double_;							
				double_.set_index(TK_float);			//����token�����Ͷ�Ϊ��С����
				double_.set_text(dou_);				//����token��������string����ʽ����
				Token.push_back(double_);					//����������Token����
			}

			{
				Token.push_back(operator_);
				if_double = false;							
				if_int = false;
				int_ = "";
				dou_ = "";
			}											//����������С�������ж���ʼ��
			
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
