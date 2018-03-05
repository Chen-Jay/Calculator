#include "parser.h"
#include "UI.h"
#include <sstream>
using std::stringstream;
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

vector<Data> Data_Array;


Data::Data(Data_type tp, double first, double second)
{
	set_data_type(tp);
	set_first_data(first);
	set_second_data(second);
}  //适用于数据的构造函数

Data::Data(Data_type tp, Sign sg)
{
	type = tp;
	sign = sg;
}		//适用于运算符号的构造函数

Data::Data(Data_type tp, double dat)
{
	set_data_type(tp) ;
	set_first_data(dat);
}//整形，浮点型的构造函数

Data::Data()
{
	;
}		//默认构造函数

void Data::set_data_type(Data_type tp)
{
	type = tp;
}

Data_type Data::get_data_type()
{
	return type;
}

void Data::set_sign(Sign sg)
{
	sign = sg;
}

Sign Data::get_sign()
{
	return sign;
}

string Data::get_sign_text()
{
	switch (sign)
	{
	case plus:
		return "plus";
		break;
	case minus:
		return "minus";
		break;
	case star:
		return "star";
		break;
	case divide:
		return "divide";
		break;
	case left:
		return "left_bracket";
		break;
	case right:
		return "right bracket";
		break;
	case caret:
		return "caret";
		break;
	case equal:
		return "equal";
		break;
	default:
		break;
	}
}

void Data::set_first_data(double fir)
{
	first_data = fir;
}

double Data::get_first_data()
{
	return first_data;
}

void Data::set_second_data(double sec)
{
	if (sec == 0)
	{
		print_first_result();
		cout << "the denominator can not be set to 0!";
		hide_the_last_cursor();
		exit(0);
	}
	second_data = sec;
}

double Data::get_second_data()
{
	return second_data;
}

void Data::set_priority(int pri)
{
	priority = pri;
}

int  Data::get_priority()
{
	return priority;
}

bool if_negetive(token now,token last)
{
	if (
			(now.get_text() == "-") &&
			(last.get_text() == "*" || last.get_text() == "/" || last.get_text() == "-" ||
			last.get_text() == "+" || last.get_text() == "=" || last.get_text() == "(" || last.get_text() == "^")
		)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool if_positive(token now, token last)
{
	if (
		(now.get_text() == "+") &&
		(last.get_text() == "*" || last.get_text() == "/" || last.get_text() == "-" ||
		last.get_text() == "+" || last.get_text() == "=" || last.get_text() == "(" || last.get_text() == "^")
		)
		
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool if_negetive(token now)
{
	if (now.get_text() == "-")
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool if_positive(token now)
{
	if (now.get_text() == "+")
	{
		return true;
	}
	else
	{
		return false;
	}

}

void Data::operator= (Data &a)
{
	type = a.get_data_type();
	first_data = a.get_first_data();
	second_data = a.get_second_data();
	priority = a.get_priority();
	sign = a.get_sign();
}

void parse()
{
	for (unsigned int i = 0; i < Token.size(); i++)
	{
		if (i == 0)
		{
			if (if_negetive(Token[i]) == true)
			{
				Data buf(compute_sign, negative);
				Data_Array.push_back(buf);
			}
			else if (if_positive(Token[i]) == true)
			{
				Data buf(compute_sign, positive);
				Data_Array.push_back(buf);
			}
			else
			{
				Data buf;
				switch (Token[i].get_type())
				{
				case Tk_negative_minus:
					buf.set_data_type(compute_sign);
					buf.set_sign(minus);
					buf.set_priority(1);
					Data_Array.push_back(buf);
					break;

				case TK_positive_plus:
					buf.set_data_type(compute_sign);
					buf.set_sign(plus);
					buf.set_priority(1);
					Data_Array.push_back(buf);
					break;

				case TK_star:
					buf.set_data_type(compute_sign);
					buf.set_sign(star);
					buf.set_priority(2);
					Data_Array.push_back(buf);
					break;

				case TK_divide:
					buf.set_data_type(compute_sign);
					buf.set_sign(divide);
					buf.set_priority(2);
					Data_Array.push_back(buf);
					break;

				case TK_lbracket:
					buf.set_data_type(compute_sign);
					buf.set_sign(left);
					buf.set_priority(100);
					Data_Array.push_back(buf);
					break;

				case TK_rbracket:
					buf.set_data_type(compute_sign);
					buf.set_sign(right);
					buf.set_priority(0);
					Data_Array.push_back(buf);
					break;

				case TK_equality:
					buf.set_data_type(compute_sign);
					buf.set_sign(equal);
					Data_Array.push_back(buf);
					break;

				case TK_caret:
					buf.set_data_type(compute_sign);
					buf.set_sign(caret);
					Data_Array.push_back(buf);
					break;
				default:
					break;
				}//判断其他的为运算符号

				Data buf2;
				stringstream ss;
				double number;
				switch (Token[i].get_type())
				{
				case TK_float:
					buf2.set_data_type(int_double);
					ss << Token[i].get_text();
					ss >> number;
					buf2.set_first_data(number);
					Data_Array.push_back(buf2);
					break;
				case TK_integer:
					buf2.set_data_type(int_double);
					ss << Token[i].get_text();
					ss >> number;
					buf2.set_first_data(number);
					Data_Array.push_back(buf2);
					break;
				default:
					break;
				}//判断数据

			}
		} //判定是否是第一个符号
		else if(if_negetive(Token[i], Token[i - 1]) == true)
		{
			Data buf(compute_sign, negative);
			Data_Array.push_back(buf);
		}	
		else if (if_positive(Token[i], Token[i - 1]) == true)
		{
			Data buf(compute_sign, positive);
			Data_Array.push_back(buf);
		}
		//正常判定
		else
		{
			Data buf;
			switch (Token[i].get_type())
			{
			case Tk_negative_minus:
				buf.set_data_type(compute_sign);
				buf.set_sign(minus);
				buf.set_priority(1);
				Data_Array.push_back(buf);
				break;

			case TK_positive_plus:
				buf.set_data_type(compute_sign);
				buf.set_sign(plus);
				buf.set_priority(1);
				Data_Array.push_back(buf);
				break;

			case TK_star:
				buf.set_data_type(compute_sign);
				buf.set_sign(star);
				buf.set_priority(2);
				Data_Array.push_back(buf);
				break;

			case TK_divide:
				buf.set_data_type(compute_sign);
				buf.set_sign(divide);
				buf.set_priority(2);
				Data_Array.push_back(buf);
				break;

			case TK_lbracket:
				buf.set_data_type(compute_sign);
				buf.set_sign(left);
				buf.set_priority(100);
				Data_Array.push_back(buf);
				break;

			case TK_rbracket:
				buf.set_data_type(compute_sign);
				buf.set_sign(right);
				buf.set_priority(0);
				Data_Array.push_back(buf);
				break;

			case TK_equality:
				buf.set_data_type(compute_sign);
				buf.set_sign(equal);
				Data_Array.push_back(buf);
				break;

			case TK_caret:
				buf.set_data_type(compute_sign);
				buf.set_sign(caret);
				Data_Array.push_back(buf);
				break;
			default:
				break;
			}//判断其他的为运算符号

			Data buf2;
			stringstream ss;
			double number;
			switch (Token[i].get_type())
			{
			case TK_float:
				buf2.set_data_type(int_double);
				ss << Token[i].get_text();
				ss >> number;
				buf2.set_first_data(number);
				Data_Array.push_back(buf2);
				break;
			case TK_integer:
				buf2.set_data_type(int_double);
				ss << Token[i].get_text();
				ss >> number;
				buf2.set_first_data(number);
				Data_Array.push_back(buf2);
				break;
			default:
				break;
			}//判断数据

		}
	}

	for (unsigned int i = 0; i < Data_Array.size(); i++)
	{
		if ((Data_Array[i].get_data_type() == compute_sign) && (Data_Array[i].get_sign() == negative))
		{
			if (Data_Array[i + 1].get_data_type() != compute_sign)
			{
				vector<Data>::iterator it1 = Data_Array.begin();
				int delete_position1 = i;
				switch (Data_Array[i + 1].get_data_type())
				{
				case int_double:
					Data_Array[i + 1].set_first_data(Data_Array[i + 1].get_first_data()*(-1));
					for (int i = 0; i <=delete_position1; i++)
					{
						if (i == delete_position1)
						{
							it1 = Data_Array.erase(it1);
						}
						else
						{
							it1++;
						}
					}
					break;
				default:
					break;
				}
			}//如果负号后面的是数据，则将负号算入后面的数据上
			else
			{
				print_first_result();
				cout << "please enter a legal expression!" ;
				hide_the_last_cursor();
				exit(0);
			}//否则就是不合法的表达式
		}

		if ((Data_Array[i].get_data_type() == compute_sign) && (Data_Array[i].get_sign() == positive))
		{
			if (Data_Array[i + 1].get_data_type() != compute_sign)
			{
				vector <Data>::iterator it2 = Data_Array.begin();
				int delete_position2 = i;
				switch (Data_Array[i + 1].get_data_type())
				{
				case int_double:
					for (int i = 0; i <=delete_position2; i++)
					{
						if (i == delete_position2)
						{
							it2 = Data_Array.erase(it2);
						}
						else
						{
							it2++;
						}
					};
					break;
				default:
					break;
				}
			}//如果正号后面的是数据，则不变
			else
			{
				print_first_result();
				cout << "please enter a legal expression!";
				hide_the_last_cursor();
				exit(0);
				return;
			}//否则输入不合法
		}
	}
}

void show_the_expression()
{
	cout << "these are the expression types:" << endl;
	for (unsigned int i = 0; i < Data_Array.size(); i++)
	{
		switch (Data_Array[i].get_data_type())
		{
		case compute_sign:
			cout << "sign ";
			break;
		case int_double:
			cout << "int_double ";
			break;
		case fraction:
			cout << "fration ";
			break;
		case power:
			cout << "power ";
			break;
		default:
			break;
		}
	}
	cout << endl;

	cout << "these are the data type:" << endl;
	for (unsigned int i = 0; i < Data_Array.size(); i++)
	{
		switch (Data_Array[i].get_data_type())
		{
		case compute_sign:
			switch (Data_Array[i].get_sign())
			{
			case negative:
				cout << "negative ";
				break;
			case positive:
				cout << "positive ";
				break;
			case plus:
				cout << "plus ";
				break;
			case minus:
				cout << "minus ";
				break;
			case star:
				cout << "star ";
				break;
			case divide:
				cout << "divide ";
				break;
			case left:
				cout << "left ";
				break;
			case right:
				cout << "right ";
				break;
			case caret:
				cout << "caret ";
				break;
			case equal:
				cout << "equal ";
				break;
			default:
				break;
			}
			break;
		case int_double:
			cout << Data_Array[i].get_first_data() << " ";
			break;
		case fraction:
			cout << Data_Array[i].get_first_data() << "/"<< Data_Array[i].get_second_data()<<' ';
			break;
		case power:
			cout << Data_Array[i].get_first_data()<< '^'<< Data_Array[i].get_second_data()<<' ';
			break;
		default:
			break;
		}
		cout << endl;
	}
}

