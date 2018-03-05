#pragma once
#include "parser.h"
#include "compute.h"
#include <vector>
using std::vector;


class Stack
{
public:
	int get_max_size();
	void push(Data);
	Data pop();
	Data get_the_top();
	void show_the_stack();
private:
	vector <Data> stack;
};

class Com_Stack
{
public:
	int get_max_size();
	void push(Compute_data);
	Compute_data pop();
	Compute_data get_the_top();
	void show_the_stack();
private:
	vector <Compute_data> stack;
};
