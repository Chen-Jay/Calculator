#pragma once
#include <vector>
using std::vector;
#include "Lexer.h"  

enum Data_type
{
	compute_sign,		//�������
	int_double,			//С��
	power,				//�˷���
	fraction,			//����
};

enum Sign
{
	negative,	//����
	positive,	//����
	plus,		//�Ӻ�
	minus,		//����
	star,		//�˺�
	divide,		//����
	left,		//������
	right,		//������
	caret,		//�˷�
	equal,		//�Ⱥ�
};

class Data
{
public:
	Data(Data_type, double, double);
	Data(Data_type, Sign);
	Data(Data_type, double);
	Data();
	void set_data_type(Data_type);
	Data_type get_data_type();
	void set_first_data(double);
	double get_first_data();
	void set_second_data(double);
	double get_second_data();
	void set_sign(Sign);
	Sign get_sign();
	void set_priority(int);
	int get_priority();
	string get_sign_text();
	void operator= (Data &a);
private:
	Data_type type;
	Sign sign;
	double first_data;			//��������ĸ��С��
	double second_data;			//ָ�������ӣ�
	int priority;				//���ȼ�
	

};

extern vector<Data> Data_Array;
bool if_negetive(token now, token last);
bool if_positive(token now, token last);
bool if_negetive(token now);
bool if_positive(token now);
void parse();
void show_the_expression();
