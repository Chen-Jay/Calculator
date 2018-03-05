#pragma once
#include "Console.h"
#include "parser.h"
#include "compute.h"

void presetting();
void print_title();
void print_first_result();
void print_first_result(Compute_data);
void hide_the_last_cursor();
void print_the_buttons();
void print_second_result(Compute_data);


void show_the_result(Compute_data result);
void show_the_result_fra_int(Compute_data result);
void show_the_result_fra(Compute_data result);
void show_the_result_val(Compute_data result);