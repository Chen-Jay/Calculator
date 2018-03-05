#pragma once
#include "stack.h"

extern vector <Data> Post_Data_Array;
extern vector <Compute_data> Com_expression;
extern Stack sta;
void change_the_expression_to_the_postfix_expression();
void change_the_postfix_expression_to_the_computing_expression();
void show_the_postfix_expression();