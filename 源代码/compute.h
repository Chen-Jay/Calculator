#pragma once
#include "parser.h"

enum Type
{
	single,		//独立数据
	Mix			//混合数据
};

class Compute_data :public Data
{
public:
	void set_coefficient(Data);
	Data get_coefficient();
	void set_type(Type);
	Type get_type();
	int get_max_size();
	Compute_data& get_the_member(int);
	void push(Compute_data);
	vector<Compute_data>::iterator get_start();
	vector<Compute_data>::iterator get_end();
	vector<Compute_data>::iterator erase(vector<Compute_data>::iterator);
private:
	Type type;						//数据类型
	Data coefficient;				//系数;
	vector <Compute_data> member;	//Mix的内容

};


Compute_data data_change(Data);

extern vector <Compute_data> Compute_expression;

Compute_data compute();

Compute_data com_plus(Compute_data a,Compute_data b);
Compute_data com_minus(Compute_data a, Compute_data b);
Compute_data com_star(Compute_data a, Compute_data b);
Compute_data com_divide(Compute_data a, Compute_data b);

void show_the_compute_expression();

bool if_int(double a);

void reduce(double& a, double& b);
void reduce(long double& a,long double& b);

void reduce_to_common(Compute_data&, Compute_data&);

void reduce_to_fraction(Compute_data &b);

double minimum(double a, double b);
int minimum(int a, int b);
long double minimum(long double a, long double b);
long long  minimum(long long  a, long long  b); 

Compute_data fraction_computing_plus(Compute_data a, Compute_data b);

Compute_data fraction_computing_star(Compute_data a,Compute_data b);
Compute_data int_fraction_computing_star(Compute_data a, Compute_data b);

int gcd(int a, int b);
long gcd(long long a, long long b);



void delete_member(Compute_data &a,int i);

void reduce_expression(Compute_data &);