#include "stack.h"
#include "UI.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;


int Stack::get_max_size()
{
	return stack.size();
}

void Stack::push(Data dat)
{
	stack.push_back(dat);
}

Data Stack::pop()
{
	if (stack.size() != 0)
	{
		Data buf;
		buf = stack[stack.size() - 1];
		stack.pop_back();
		return buf;
	}
	else
	{
		print_first_result();
		cerr << "your expression is not legal,please enter a legal one!";
		hide_the_last_cursor();
		exit(0);
	}
}

Data Stack::get_the_top()
{
	return stack[stack.size() - 1];
}

void Stack::show_the_stack()
{
	cout << "these are the things in the stack" << endl;
	for (int i = 0; i < stack.size(); i++)
	{
		cout << "type:" << stack[i].get_data_type()<<" ";
		if (stack[i].get_data_type() == compute_sign)
		{
			cout << "sign: " << stack[i].get_sign()<<" ";
		}
		else if (stack[i].get_data_type() == int_double)
		{
			cout << "first_data: " << stack[i].get_first_data()<<" ";
			//cout << "second data: " << stack[i].get_second_data() << " ";
		}
		//cout << "priority: " << stack[i].get_priority() << " " << endl;
		cout << endl;
	}
}


int Com_Stack::get_max_size()
{
	return stack.size();
}

void Com_Stack::push(Compute_data dat)
{
	stack.push_back(dat);
}

Compute_data Com_Stack::pop()
{
	if (stack.size() != 0)
	{
		Compute_data buf;
		buf = stack[stack.size() - 1];
		stack.pop_back();
		return buf;
	}
	else
	{
		print_first_result();
		cerr << "your expression is not legal,please enter a legal one!";
		hide_the_last_cursor();
		exit(0);
	}
}

Compute_data Com_Stack::get_the_top()
{
	return stack[stack.size() - 1];
}
