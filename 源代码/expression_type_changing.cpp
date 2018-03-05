#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
#include "parser.h"
#include "stack.h"
#include "expression_type_changing.h"

vector <Data> Post_Data_Array;
vector <Compute_data> Com_expression;
void change_the_expression_to_the_postfix_expression()
{
	Stack sta;
	for (int i = 0; i < Data_Array.size(); i++)
	{
		if (Data_Array[i].get_data_type() == compute_sign)
		{
			if (Data_Array[i].get_sign() == equal)
			{
				for (int j = sta.get_max_size() - 1; j >= 0; j--)
				{
					Data pop;
					pop = sta.pop();
					Post_Data_Array.push_back(pop);
				}
				break;
			}

			else if (Data_Array[i].get_sign() == left)
			{
				Data_Array[i].set_priority(0);
				sta.push(Data_Array[i]);
			}

			else if (Data_Array[i].get_sign() == right)
			{

				for (int h = sta.get_max_size()-1; h >= 0; h--)
				{
					if (sta.get_the_top().get_sign()!=left)
					{
						Data pop;
						pop = sta.pop();
						Post_Data_Array.push_back(pop);
					}
					else 
					{
						Data pop;
						pop = sta.pop();
						break;
					}

				}
			}
			else
			{
				if (Data_Array[i].get_data_type() == compute_sign)
				{
					if (sta.get_max_size() == 0)
					{
						sta.push(Data_Array[i]);
					}
					else
					{
						Data buf;
						buf = sta.get_the_top();
						if (Data_Array[i].get_priority() > buf.get_priority())
						{
							sta.push(Data_Array[i]);
						}
						else
						{
							for (int k = 0; k < sta.get_max_size(); k++)
							{
								if (Data_Array[i].get_priority() <= sta.get_the_top().get_priority())
								{
									Data pop;
									pop = sta.pop();
									Post_Data_Array.push_back(pop);
								}
								else
								{
									break;
								}
							}
							sta.push(Data_Array[i]);
						}
					}
				}
			}
		}
		else
		{
			Post_Data_Array.push_back(Data_Array[i]);
		}
	}
}
void change_the_postfix_expression_to_the_computing_expression()
{
	for (int i = 0; i < Post_Data_Array.size(); i++)
	{
		Com_expression.push_back(data_change(Post_Data_Array[i]));
	}
}

void show_the_postfix_expression()
{
	for (int i = 0; i < Post_Data_Array.size(); i++)
	{
		cout << "type:" << Post_Data_Array[i].get_data_type() << " ";
		if (Post_Data_Array[i].get_data_type() == compute_sign)
		{
			cout << "sign: " << Post_Data_Array[i].get_sign_text() << " ";
		}
		else if (Post_Data_Array[i].get_data_type() == int_double)
		{
			cout << "first_data: " << Post_Data_Array[i].get_first_data() << " ";
			//cout << "second data: " << stack[i].get_second_data() << " ";
		}
		//cout << "priority: " << stack[i].get_priority() << " " << endl;
		cout << endl;
	}
}
