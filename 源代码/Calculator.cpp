


#include "Lexer.h"
#include "parser.h"
#include "stack.h"
#include "expression_type_changing.h"
#include "compute.h"
#include "UI.h"
#include "Console.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
#include <iomanip>
using std::setprecision;
int main()
{
	presetting();
	print_title();
	lexical_analysis();
	parse();
	change_the_expression_to_the_postfix_expression();
	change_the_postfix_expression_to_the_computing_expression();
	print_first_result(compute());
	compute();
	print_the_buttons();
	print_second_result(compute());
	

	/*console.moveCursorTo(45, 25);
	cout << "0";*/
	
	hide_the_last_cursor();
	/*Stack a;
	Data dat1(int_double,1);
	Data dat2(compute_sign,minus);
	a.push(dat1);
	a.push(dat2);
	a.show_the_stack();
	Stack b;
	Data dat3=a.pop();
	b.push(dat3);
	a.show_the_stack();
	b.show_the_stack();*/
	
    return 0;
}

