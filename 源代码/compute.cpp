#include "compute.h"
#include "expression_type_changing.h"
#include "UI.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cmath>
using std::modf;
#include <iomanip>
using std::setprecision;
#include <sstream>
using std::stringstream;
#include <string>
using std::string;


vector <Compute_data> Compute_expression;

void Compute_data::set_coefficient(Data dat)
{
	coefficient=dat;
	return;
}

Data Compute_data::get_coefficient()
{
	return coefficient;
}

int Compute_data::get_max_size()
{
	return member.size();
}

Compute_data& Compute_data::get_the_member(int n)
{
	Compute_data &mem = member[n];
	return mem;
}

void Compute_data::push(Compute_data data)
{
	member.push_back(data);
	return;
}

void Compute_data::set_type(Type tp)
{
	type = tp;
}

Type Compute_data::get_type()
{
	return type;
}

vector<Compute_data>::iterator Compute_data::get_start()
{
	return member.begin();
}

vector<Compute_data>::iterator Compute_data::get_end()
{
	return member.end();
}

vector<Compute_data>::iterator Compute_data::erase(vector<Compute_data>::iterator it)
{
	return member.erase(it);
}

Compute_data data_change(Data a)
{
	Compute_data after_change;
	Data coe(int_double,1);
	
	if (a.get_data_type() == compute_sign)
	{
		after_change.set_type(single);
		after_change.set_data_type(a.get_data_type());
		after_change.set_priority(a.get_priority());
		after_change.set_sign(a.get_sign());
		return after_change;
	}
	else if (a.get_data_type() == int_double)
	{
		after_change.set_type(single);
		after_change.set_data_type(a.get_data_type());
		after_change.set_first_data(a.get_first_data());
		return after_change;
	}
	else if (a.get_data_type() == power)
	{
		after_change.set_type(single);
		after_change.set_data_type(a.get_data_type());
		after_change.set_first_data(a.get_first_data());
		after_change.set_second_data(a.get_second_data());
		after_change.set_coefficient(coe);
		return after_change;
	}
	else if (a.get_data_type() == fraction)
	{
		after_change.set_type(single);
		after_change.set_data_type(a.get_data_type());
		after_change.set_first_data(a.get_first_data());
		after_change.set_second_data(a.get_second_data());
		after_change.set_coefficient(coe);
		return after_change;
	}

}

Compute_data com_plus(Compute_data a, Compute_data b)
{
	Compute_data result;
	Compute_data &result_ = result;
	Data coe(int_double, 1);
	Compute_data &a_ = a;
	Compute_data &b_ = b;
	if (a.get_type() == single&&b.get_type() == single)
	{
		if (a.get_data_type() == int_double&&b.get_data_type() == int_double)
		{
			result.set_data_type(int_double);
			result.set_first_data(a.get_first_data() + b.get_first_data());
			result.set_type(single);
			if (if_int(result.get_first_data()) == true)
			{
				result.set_data_type(int_double);
				return (result);
			}
			else
			{
				result.set_data_type(fraction);
				result.set_second_data(1);
				reduce_to_fraction(result_);
				if (result.get_second_data() == 1)
				{
					result.set_data_type(int_double);
				}
				return result;
			}
		}
		else if (a.get_data_type() == fraction&&b.get_data_type() == fraction)
		{
			return fraction_computing_plus(a, b);
		}
		else if (a.get_data_type() == int_double&&b.get_data_type() == fraction)
		{
			Compute_data result;
			Data coe(int_double, 1);
			result.set_type(single);
			result.set_data_type(fraction);
			result.set_second_data(b.get_second_data());
			result.set_first_data(b.get_second_data()*a.get_first_data() + b.get_first_data());
			double fir = result.get_first_data();
			double sec = result.get_second_data();
			while ((if_int(fir) == false) || (if_int(sec) == false))
			{

				fir *= 10.0;
				sec *= 10.0;
			}

			double &f_ = fir;
			double &s_ = sec;
			//cout << std::setprecision(50)<<"f: " << f_ << "s: " << s_ << endl;
			reduce(f_, s_);
			result.set_first_data(fir);
			result.set_second_data(sec);

			if (if_int(result.get_first_data() / result.get_second_data()) == true)
			{
				result.set_data_type(int_double);
				result.set_first_data(result.get_first_data() / result.get_second_data());
				return (result);
			}
			else
			{
				result.set_data_type(fraction);
				return result;
			}
		}
		else if (b.get_data_type() == int_double&&a.get_data_type() == fraction)
		{
			Compute_data result;
			Data coe(int_double, 1);

			result.set_data_type(fraction);
			result.set_second_data(a.get_second_data());
			result.set_first_data(a.get_second_data()*b.get_first_data() + a.get_first_data());
			result.set_coefficient(coe);
			result.set_type(single);
			double fir = result.get_first_data();
			double sec = result.get_second_data();
			while ((if_int(fir) == false) || (if_int(sec) == false))
			{

				fir *= 10.0;
				sec *= 10.0;
			}
			double &f_ = fir;
			double &s_ = sec;
			//cout << std::setprecision(50)<<"f: " << f_ << "s: " << s_ << endl;
			reduce(f_, s_);
			result.set_first_data(fir);
			result.set_second_data(sec);

			if (if_int(result.get_first_data() / result.get_second_data()) == true)
			{
				result.set_data_type(int_double);
				result.set_first_data(result.get_first_data() / result.get_second_data());
				return (result);
			}
			else
			{
				result.set_data_type(fraction);
				return result;
			}
		}
	}
	else if (a.get_type() == Mix&&b.get_type() == single)
	{
		if (b.get_data_type() == int_double)
		{
			for (int i = 0; i < a.get_max_size(); i++)
			{
				if (a.get_the_member(i).get_data_type() == int_double)
				{
					a.get_the_member(i).set_first_data(a.get_the_member(i).get_first_data() + b.get_first_data());
					return a;
					break;
				}
			}
			if (if_int(b.get_first_data()) == true)
			{
				for (int i = 0; i < a.get_max_size(); i++)
				{
					if (a.get_the_member(i).get_data_type() == fraction)
					{
						a.get_the_member(i).set_first_data(a.get_first_data() + (b.get_first_data()*a.get_second_data()));
					}
					break;
				}
				return a;
			}
			else
			{
				a.push(b);
				return a;
			}
		}
		else if (b.get_data_type() == fraction)
		{
			for (int i = 0; i < a.get_max_size(); i++)
			{
				if (a.get_the_member(i).get_data_type() == int_double)
				{
					if (if_int(a.get_the_member(i).get_first_data()) == true)
					{
						a.get_the_member(i).set_data_type(fraction);
						a.get_the_member(i).set_first_data(a.get_first_data()*b.get_second_data() + b.get_first_data());
						a.get_the_member(i).set_second_data(b.get_second_data());
						a.get_the_member(i).set_coefficient(coe);
						return a;
					}
				}
				else if ((a.get_the_member(i).get_data_type() == fraction))
				{
					result = fraction_computing_plus(a.get_the_member(i), b);
					a.get_the_member(i) = result;
					return a;
				}
				else
				{
					a.push(b);
					return a;
				}
			}
		}

	}
	else if (a.get_type() == single&&b.get_type() == Mix)
	{
		if (a.get_data_type() == int_double)
		{
			for (int i = 0; i < b.get_max_size(); i++)
			{
				if (b.get_the_member(i).get_data_type() == int_double)
				{
					b.get_the_member(i).set_first_data(b.get_the_member(i).get_first_data() + a.get_first_data());
					return b;
					break;
				}
			}
			if (if_int(a.get_first_data()) == true)
			{
				for (int i = 0; i < b.get_max_size(); i++)
				{
					if (b.get_the_member(i).get_data_type() == fraction)
					{
						b.get_the_member(i).set_first_data(b.get_the_member(i).get_first_data() + (a.get_first_data()*b.get_the_member(i).get_second_data()));
					}
					break;
				}
				return b;
			}
			else
			{
				b.push(a);
				return b;
			}
		}
		else if (b.get_data_type() == fraction)
		{
			for (int i = 0; i < a.get_max_size(); i++)
			{
				if (a.get_the_member(i).get_data_type() == int_double)
				{
					if (if_int(a.get_the_member(i).get_first_data()) == true)
					{
						a.get_the_member(i).set_data_type(fraction);
						a.get_the_member(i).set_first_data(a.get_first_data()*b.get_second_data() + b.get_first_data());
						a.get_the_member(i).set_second_data(b.get_second_data());
						a.get_the_member(i).set_coefficient(coe);
						return a;
					}
				}
				else if ((a.get_the_member(i).get_data_type() == fraction))
				{
					result = fraction_computing_plus(a.get_the_member(i), b);
					return result;
				}
				else
				{
					a.push(b);
					return a;
				}
			}
		}

	}
	else if (a.get_type() == Mix&&b.get_type() == Mix)
	{
		vector <int> no;
		vector <int> yes;
		vector <int> last_no;
		vector <int> last_yes;
		for (int i = 0; i < b.get_max_size(); i++)
		{
			for (int j = 0; j < a.get_max_size(); j++)
			{
				if (a.get_the_member(j).get_data_type() == int_double&&b.get_the_member(i).get_data_type() == int_double)
				{
					a.get_the_member(j).set_first_data(a.get_the_member(j).get_first_data() + b.get_the_member(i).get_first_data());
					break;
				}
				else if (a.get_the_member(j).get_data_type() == fraction&&b.get_the_member(i).get_data_type() == fraction)
				{
					a.get_the_member(j) = fraction_computing_plus(a.get_the_member(j), b.get_the_member(i));
					break;
				}
				no.push_back(i);
			}

		}

		for (unsigned int j = 0; j < no.size(); j++)
		{
			bool ok = false;
			for (int i = 0; i < a.get_max_size(); i++)
			{
				if (a.get_the_member(i).get_data_type() == int_double&&b.get_the_member(no[j]).get_data_type() == fraction)
				{
					Compute_data result;
					Data coe(int_double, 1);
					if (if_int(a.get_the_member(i).get_first_data()) == true)
					{
						a.get_the_member(i).set_data_type(fraction);
						a.get_the_member(i).set_second_data(b.get_the_member(j).get_second_data());
						a.get_the_member(i).set_first_data(b.get_second_data()*a.get_first_data() + b.get_first_data());
						a.get_the_member(i).set_coefficient(coe);
						a.get_the_member(i).set_type(single);
					}
					ok = true;
					continue;
				}
				else if (b.get_the_member(no[j]).get_data_type() == int_double&&a.get_the_member(i).get_data_type() == fraction)
				{
					Compute_data result;
					Data coe(int_double, 1);
					if (if_int(b.get_the_member(i).get_first_data()) == true)
					{
						a.get_the_member(i).set_data_type(fraction);
						a.get_the_member(i).set_first_data(b.get_the_member(j).get_first_data()*a.get_the_member(i).get_second_data() + a.get_first_data());
						a.get_the_member(i).set_coefficient(coe);
					}
					ok = true;
					continue;
				}
			}
			if (ok == false)
			{
				last_no.push_back(no[j]);
			}

		}
		for (int i = 0; i < last_no.size(); i++)
		{
			a.push(b.get_the_member(last_no[i]));
		}
		return a;
	}
}

Compute_data com_minus(Compute_data a, Compute_data b)
{
	if (a.get_type() == single&&b.get_type() == single)
	{
		if (a.get_data_type() == int_double&&b.get_data_type() == int_double)
		{
			b.set_first_data(b.get_first_data()*(-1));
			return com_plus(a, b);
		}
		else if (a.get_data_type() == fraction&&b.get_data_type() == fraction)
		{
			b.set_first_data(b.get_first_data()*(-1));
			return com_plus(a, b);
		}
		else if (a.get_data_type() == int_double&&b.get_data_type() == fraction)
		{
			b.set_first_data(b.get_first_data()*(-1));
			return com_plus(a, b);
		}
		else if (b.get_data_type() == int_double&&a.get_data_type() == fraction)
		{
			b.set_first_data(b.get_first_data()*(-1));
			return com_plus(a, b);
		}
	}
	else if (a.get_type() == Mix&&b.get_type() == single)
	{
		if (b.get_data_type() == int_double)
		{
			b.set_first_data(b.get_first_data()*(-1));
			return com_plus(a, b);
		}
		else if (b.get_data_type() == fraction)
		{
			b.set_first_data(b.get_first_data()*(-1));
			return com_plus(a, b);
		}
	}
	else if (a.get_type() == single&&b.get_type() == Mix)
	{
		for (int i = 0; i < b.get_max_size(); i++)
		{
			b.get_the_member(i).set_first_data(b.get_the_member(i).get_first_data()*(-1));
		}
		return com_plus(a, b);
	}
	else if (a.get_type() == Mix&&b.get_type() == Mix)
	{
		for (int i = 0; i < b.get_max_size(); i++)
		{
			b.get_the_member(i).set_first_data(b.get_the_member(i).get_first_data()*(-1));
		}
		return com_plus(a, b);
	}

}

Compute_data com_star(Compute_data a, Compute_data b)
{
	Compute_data result;
	Compute_data &result_ = result;
	Data coe(int_double, 1);

	Compute_data &a_ = a;
	Compute_data &b_ = b;

	if (a.get_type() == single&&b.get_type() == single)
	{
		if (a.get_data_type() == int_double&&b.get_data_type() == int_double)
		{
			result.set_first_data(a.get_first_data()*b.get_first_data());
			result.set_type(single);
			if (if_int(result.get_first_data()) == true)
			{
				result.set_data_type(int_double);
				return (result);
			}
			else
			{
				result.set_data_type(fraction);
				result.set_second_data(1);
				reduce_to_fraction(result_);
				if (result.get_second_data()==1)
				{
					result.set_data_type(int_double);
				}
				return result;
			}
		}
		else if (a.get_data_type() == fraction&&b.get_data_type() == fraction)
		{
			return fraction_computing_star(a, b);
		}
		else if (a.get_data_type() == int_double&&b.get_data_type() == fraction)
		{
			return int_fraction_computing_star(a, b);
		}
		else if (b.get_data_type() == int_double&&a.get_data_type() == fraction)
		{
			return int_fraction_computing_star(b, a);
		}
	}
	else if (a.get_type() == Mix&&b.get_type() == single)
	{
		if (b.get_data_type() == int_double)
		{
			for (int i = 0; i < a.get_max_size(); i++)
			{
				if (a.get_the_member(i).get_data_type() == int_double)
				{
					a.get_the_member(i).set_first_data(a.get_the_member(i).get_first_data()*b.get_first_data());
				}
				if (a.get_the_member(i).get_data_type() == fraction)
				{
					a.get_the_member(i) = int_fraction_computing_star(b, a.get_the_member(i));
				}
			}
			Compute_data &a_ = a;
			reduce_expression(a_);
			return a;
		}
		else if (b.get_data_type() == fraction)
		{
			for (int i = 0; i < a.get_max_size(); i++)
			{
				if (a.get_the_member(i).get_data_type() == int_double)
				{	
					a.get_the_member(i)=int_fraction_computing_star(a.get_the_member(i), b);
				}
				else if (a.get_the_member(i).get_data_type() == fraction)
				{
					a.get_the_member(i) = fraction_computing_star(a.get_the_member(i), b);
				}
			}
			Compute_data &a_ = a;
			reduce_expression(a_);
			return a;
		}
	}
	else if (b.get_type() == Mix&&a.get_type() == single)
	{
		if (a.get_data_type() == int_double)
		{
			for (int i = 0; i < b.get_max_size(); i++)
			{
				if (b.get_the_member(i).get_data_type() == int_double)
				{
					b.get_the_member(i).set_first_data(b.get_the_member(i).get_first_data()*a.get_first_data());
				}
				else if (b.get_the_member(i).get_data_type() == fraction)
				{
					b.get_the_member(i) = int_fraction_computing_star(a, b.get_the_member(i));
				}
			}
			Compute_data &b_ = b;
			reduce_expression(b_);
			return b;
		}
		if (a.get_data_type() == fraction)
		{
			for (int i = 0; i < b.get_max_size(); i++)
			{
				if (b.get_the_member(i).get_data_type() == int_double)
				{
					b.get_the_member(i) = int_fraction_computing_star(b.get_the_member(i), a);
				}
				else if (b.get_the_member(i).get_data_type() == fraction)
				{
					b.get_the_member(i) = fraction_computing_star(a, b.get_the_member(i));
				}
			}
			Compute_data &b_ = b;
			reduce_expression(b_);
			return b;
		}
	}
	else if (a.get_type() == Mix&&b.get_type() == Mix)
	{
		Compute_data result_;
		result.set_type(Mix);
		for (int i = 0; i < a.get_max_size(); i++)
		{
			for (int j = 0; j < b.get_max_size(); j++)
			{
				if (a.get_the_member(i).get_data_type() == int_double)
				{
					if (b.get_the_member(j).get_data_type() == int_double)
					{
						Compute_data buf1;
						buf1.set_type(single);
						buf1.set_data_type(int_double);
						buf1.set_first_data(a.get_the_member(i).get_first_data()*b.get_the_member(j).get_first_data());
						result_.push(buf1);
					}
					else if (b.get_the_member(j).get_data_type() == fraction)
					{
						Compute_data buf2;
						buf2 = int_fraction_computing_star(a.get_the_member(i), b.get_the_member(j));
						result_.push(buf2);
					}
				}
				else if (a.get_the_member(i).get_data_type() == fraction)
				{
					if (b.get_the_member(j).get_data_type() == int_double)
					{
						Compute_data buf1;
						buf1 = int_fraction_computing_star(b.get_the_member(j), a.get_the_member(i));
						result_.push(buf1);
					}
					else if (b.get_the_member(j).get_data_type() == fraction)
					{
						Compute_data buf2;
						buf2 = fraction_computing_star(a.get_the_member(i), b.get_the_member(j));
						result_.push(buf2);
					}
				}
			}
		}
		Compute_data &result__ = result_;
		reduce_expression(result__);
		return result_;
	}

}

Compute_data com_divide(Compute_data a, Compute_data b)
{
	Compute_data result;
	Data coe(int_double, 1);
	Compute_data &a_ = a;
	Compute_data &b_ = b;

	if (a.get_type() == single&&b.get_type() == single)
	{
		if (a.get_data_type() == int_double&&b.get_data_type() == int_double)
		{
			b.set_data_type(fraction);
			b.set_second_data(b.get_first_data());
			b.set_first_data(1);
			return com_star(a, b);
		}
		else if (a.get_data_type() == fraction&&b.get_data_type() == fraction)
		{
			double buf;
			buf = b.get_first_data();
			b.set_first_data(b.get_second_data());
			b.set_second_data(buf);
			return com_star(a,b);
		}
		else if (a.get_data_type() == int_double&&b.get_data_type() == fraction)
		{
			double buf;
			buf = b.get_first_data();
			b.set_first_data(b.get_second_data());
			b.set_second_data(buf);
			return com_star(a, b);
		}
		else if (b.get_data_type() == int_double&&a.get_data_type() == fraction)
		{
			b.set_data_type(fraction);
			b.set_second_data(b.get_first_data());
			b.set_first_data(1);
			return com_star(a, b);
		}
	}
	else if (a.get_type() == Mix&&b.get_type() == single)
	{
		if (b.get_data_type() == int_double)
		{
			if (b.get_data_type() == int_double)
			{
				b.set_data_type(fraction);
				b.set_second_data(b.get_first_data());
				b.set_first_data(1);
				return com_star(a, b);
			}
			else if (b.get_data_type() == fraction)
			{
				double buf;
				buf = b.get_first_data();
				b.set_first_data(b.get_second_data());
				b.set_second_data(buf);
				return com_star(a, b);
			}

		}
	}
	else if (b.get_type() == Mix&&a.get_type() == single)
	{
		for (int i = 0; i < b.get_max_size(); i++)
		{
			if (b.get_the_member(i).get_data_type() == int_double)
			{
				b.get_the_member(i).set_data_type(fraction);
				b.get_the_member(i).set_second_data(b.get_first_data());
				b.get_the_member(i).set_first_data(1);
			}
			else if (b.get_the_member(i).get_data_type() == fraction)
			{
				double buf;
				buf = b.get_first_data();
				b.set_first_data(b.get_second_data());
				b.set_second_data(buf);
			}
		}
		return com_star(a, b);
	}
	else if (a.get_type() == Mix&&b.get_type() == Mix)
	{
		/*for (int i = 0; i < b.get_max_size(); i++)
		{
			if (b.get_the_member(i).get_data_type() == int_double)
			{
				b.get_the_member(i).set_data_type(fraction);
				b.get_the_member(i).set_second_data(b.get_the_member(i).get_first_data());
				b.get_the_member(i).set_first_data(1);
			}
			else if (b.get_the_member(i).get_data_type() == fraction)
			{
				double buf;
				buf = b.get_the_member(i).get_first_data();
				b.get_the_member(i).set_first_data(b.get_the_member(i).get_second_data());
				b.get_the_member(i).set_second_data(buf);
			}
		}*/
		Compute_data &b_ = b;
		for (int i = 0; i < b.get_max_size(); i++)
		{
			if (b.get_the_member(i).get_data_type() == int_double)
			{
				for (int j = 0; j != i&&j < b.get_max_size(); j++)
				{
					if (b.get_the_member(j).get_data_type() == fraction)
					{
						b.get_the_member(i).set_data_type(fraction);
						b.get_the_member(i).set_first_data(b.get_the_member(i).get_first_data()*b.get_the_member(j).get_second_data() + b.get_the_member(j).get_first_data());
						b.get_the_member(i).set_second_data(b.get_the_member(j).get_second_data());
						delete_member(b_, j);
						break;
					}
					else if (b.get_the_member(j).get_data_type() == int_double)
					{
						b.get_the_member(i).set_first_data(b.get_the_member(i).get_first_data() + b.get_the_member(j).get_first_data());
						delete_member(b_,j);
					}
				}
				if (b.get_max_size() == 1)
				{
					b.set_type(single);
					b.set_data_type(b.get_the_member(0).get_data_type());
					b.set_first_data(b.get_the_member(0).get_first_data());
					b.set_second_data(b.get_the_member(0).get_second_data());
					delete_member(b_, 0);
				}
				if (b.get_type() == single)
				{
					if (b.get_data_type() == int_double)
					{
						b.set_data_type(fraction);
						b.set_second_data(b.get_first_data());
						b.set_first_data(1);
					}
					else if (b.get_data_type() == fraction)
					{
						double buf;
						buf = b.get_first_data();
						b.set_first_data(b.get_second_data());
						b.set_second_data(buf);
					}
				}
			}
			else if (b.get_the_member(i).get_data_type() == fraction)
			{
				for (int j = 0; j != i&&j < b.get_max_size(); j++)
				{
					if (b.get_the_member(j).get_data_type() == fraction)
					{
						b.get_the_member(i) = com_plus(b.get_the_member(i), b.get_the_member(j));
						delete_member(b_, j);
					}
					else if (b.get_the_member(j).get_data_type() == int_double)
					{
						b.get_the_member(i).set_first_data(b.get_the_member(i).get_first_data() + b.get_the_member(j).get_first_data()*b.get_the_member(i).get_second_data());
						double fir = b.get_the_member(i).get_first_data();
						double sec = b.get_the_member(i).get_second_data();
						while ((if_int(fir) == false) || (if_int(sec) == false))
						{

							fir *= 10.0;
							sec *= 10.0;
						}

						double &f_ = fir;
						double &s_ = sec;
						//cout << std::setprecision(50)<<"f: " << f_ << "s: " << s_ << endl;
						reduce(f_, s_);
						b.get_the_member(i).set_first_data(fir);
						b.get_the_member(i).set_second_data(sec);
						delete_member(b_, j);
						
					}
				}
				if (b.get_max_size() == 1)
				{
					b.set_type(single);
					b.set_data_type(b.get_the_member(0).get_data_type());
					b.set_first_data(b.get_the_member(0).get_first_data());
					b.set_second_data(b.get_the_member(0).get_second_data());
					delete_member(b_, 0);
				}

				if (b.get_type() == single)
				{
					if (b.get_data_type() == int_double)
					{
						b.set_data_type(fraction);
						b.set_second_data(b.get_first_data());
						b.set_first_data(1);
					}
					else if (b.get_data_type() == fraction)
					{
						b.set_data_type(fraction);
						double buf;
						buf = b.get_first_data();
						b.set_first_data(b.get_second_data());
						b.set_second_data(buf);
					}
				}

			}
		}
		return com_star(a, b);
	}
}

void show_the_compute_expression()
{
	cout << "this is the expression" << endl;
	for (int i = 0; i < Compute_expression.size(); i++)
	{
		cout << "type:" << Compute_expression[i].get_data_type() << " ";
		if (Compute_expression[i].get_data_type() == compute_sign)
		{
			cout << "sign: " << Compute_expression[i].get_sign_text() << " ";
		}
		else if (Compute_expression[i].get_data_type() == int_double)
		{
			cout << "first_data: " << Compute_expression[i].get_first_data() << " ";
			//cout << "second data: " << Compute_expression[i].get_second_data() << " ";
		}
		//cout << "priority: " << Compute_expression[i].get_priority() << " " << endl;
		cout << endl;
	}
}

bool if_int(double a)
{
	/*if (a - int(a) <0.0000001&& a-int(a)>(-0.0000001))
	{
		return true;
	}
	else
	{
		return false;
	}*/
	double xiao;
	double zheng;
	xiao = modf(a, &zheng);

	if (xiao < 0.00000001&&xiao > -0.00000001)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void reduce(double &a, double &b)
{
	double min;
	double buf1;
	double buf2;
	modf(a, &buf1);
	modf(b, &buf2);
	//cout <<std::setprecision(15)<<"buf1: " << buf1 << endl << "buf2: " << buf2 << endl;
	long long  fir_ = long long(buf1);
	long long	sec_ = long long(buf2);
	//cout << std::setprecision(15)<< "fir_: " << fir_ <<endl<< "sec_: " << sec_<<endl;
	while (gcd(fir_, sec_) != 1)
	{
		long long buf = gcd(fir_, sec_);
		a /= buf;
		b /= buf;
		fir_ /= buf;
		sec_ /= buf;
	}
}

void reduce(long double &a, long double &b)
{
	long double min;
	int fir_ = int(a);
	int sec_ = int(b);

	if (a == b)
	{
		a = 1;
		b = 1;
		return;
	}
	else
	{
		min = minimum(a, b);
	}

	while (gcd(fir_, sec_) != 1)
	{
		long long buf = gcd(fir_, sec_);
		a /= buf;
		b /= buf;
		fir_ /= buf;
		sec_ /= buf;
	}
}

void reduce_to_common(Compute_data &a, Compute_data &b)
{
	a.set_first_data(a.get_first_data()*b.get_second_data());
	b.set_first_data(b.get_first_data()*a.get_second_data());
	a.set_second_data(a.get_second_data()*b.get_second_data());
	b.set_second_data(a.get_second_data());
	return;
}

void reduce_to_fraction(Compute_data &b)
{
	double fir = b.get_first_data();
	double sec = b.get_second_data();
	while ((if_int(fir) == false) || (if_int(sec) == false))
	{

		fir *= 10.0;
		sec *= 10.0;
	}
	double &f_ = fir;
	double &s_ = sec;
	//cout << std::setprecision(50)<<"f: " << f_ << "s: " << s_ << endl;
	reduce(f_, s_);

	b.set_first_data(fir);
	b.set_second_data(sec);
}

int minimum(int a, int b)
{
	int min;
	if (a<=b)
	{
		min = a;
	}
	else
	{
		min = b;
	}
	return min;
}
double minimum(double a, double b)
{
	double min;
	if (a <= b)
	{
		min = a;
	}
	else
	{
		min = b;
	}
	return min;
};
long double minimum(long double a, long double b)
{
	long double min;
	if (a <= b)
	{
		min = a;
	}
	else
	{
		min = b;
	}
	return min;
}
long long  minimum(long long  a, long long  b)
{
	long long  min;
	if (a <= b)
	{
		min = a;
	}
	else
	{
		min = b;
	}
	return min;
};

int gcd(int a, int b)
{
	if (a < 0)
	{
		a = -1 * a;
	}
	if (b < 0) 
	{
		b = -1 * b;
	}
		int r;
		while (b>0)
		{
			r = a%b;
			a = b;
			b = r;
		}
		return a;
}
long gcd(long long a, long long b)
{
	if (a < 0)
	{
		a = -1 * a;
	}
	if (b < 0)
	{
		b = -1 * b;
	}
	long long r;
	while (b>0)
	{
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

Compute_data fraction_computing_plus(Compute_data a, Compute_data b)
{
	Compute_data result;
	Data coe(int_double, 1);
	Compute_data &a_ = a;
	Compute_data &b_ = b;
	result.set_type(single);

	if (a.get_second_data() == b.get_second_data())
	{
		result.set_first_data(a.get_first_data() + b.get_first_data());
		result.set_second_data(a.get_second_data());
		double buf = result.get_first_data() / result.get_second_data();
		if (if_int(buf) == true)
		{
			result.set_data_type(int_double);
			result.set_first_data(buf);
			return result;
		}
		else
		{
			double fir = result.get_first_data();
			double sec = result.get_second_data();
			while ((if_int(fir) == false) || (if_int(sec) == false))
			{

				fir *= 10.0;
				sec *= 10.0;
			}

			double &f_ = fir;
			double &s_ = sec;
			//cout << std::setprecision(50)<<"f: " << f_ << "s: " << s_ << endl;
			reduce(f_, s_);

			result.set_first_data(fir);
			result.set_second_data(sec);
			result.set_data_type(fraction);
			return result;
		}
	}//分母相等
	else
	{
		reduce_to_common(a_, b_);		//通分
		/*cout << "a: " << a.get_first_data() << "/" << a.get_second_data() << endl;
		cout << "b: " << b.get_first_data() << "/" << b.get_second_data() << endl;*/
		double fir = a.get_first_data() + b.get_first_data();
		double sec = a.get_second_data();
		/*cout << fir << "/" << sec << endl;*/
		if (fir == sec)
		{
			result.set_data_type(int_double);
			result.set_first_data(1);
			return result;
		}		//分子分母相等

		else
		{
			double buf = fir / sec;
			if (if_int(buf) == true)
			{
				result.set_data_type(int_double);
				result.set_first_data(buf);
				return result;
			}			//结果是整数
			else
			{
				if (if_int(fir) == true && if_int(sec) == true)
				{
					double &f_ = fir;
					double &s_ = sec;
					reduce(f_, s_);
					result.set_first_data(fir);
					result.set_second_data(sec);
					result.set_data_type(fraction);
					return result;
				}		//如果结果不是整数，但是分子分母都是整数，进行约分。
				else
				{
					while (if_int(fir) == false || if_int(sec) == false)
					{
						fir *= 10;
						sec *= 10;
					}
					double &f_ = fir;
					double &s_ = sec;
					reduce(f_, s_);
					if (if_int(f_ / s_) == true)
					{
						result.set_data_type(int_double);
						result.set_first_data(f_ / s_);
						return result;
					}
					else
					{
						result.set_first_data(fir);
						result.set_second_data(sec);
						result.set_data_type(fraction);
						result.set_coefficient(coe);
						return result;
					}

				}			//如果分子或者分母有一个不是整数，同时乘10，然后重复至两者均为整数，然后约分

			}
		}		//分子分母不相等

	}
}

Compute_data fraction_computing_star(Compute_data a, Compute_data b)
{
	Compute_data result;
	Data coe(int_double, 1);
	Compute_data &a_ = a;
	Compute_data &b_ = b;
	//cout << a.get_first_data() << endl << b.get_first_data() << endl;
	result.set_first_data(a.get_first_data()*b.get_first_data());

	result.set_second_data(a.get_second_data()*b.get_second_data());
	double fir_ = result.get_first_data();
	double sec_ = result.get_second_data();
	double &f_ = fir_;
	double &s_ = sec_;
	reduce(f_, s_);
	result.set_first_data(fir_);
	result.set_second_data(sec_);
	double buf = result.get_first_data() / result.get_second_data();
	//cout << buf << endl;
	if (if_int(buf) == true)
	{
		result.set_data_type(int_double);
		result.set_first_data(buf);
		result.set_type(single);
		return result;
	}
	else
	{
		double fir = result.get_first_data();
		double sec = result.get_second_data();
		while ((if_int(fir) == false) || (if_int(sec) == false))
		{
			fir *= 10.0;
			sec *= 10.0;
		}

		double &f_ = fir;
		double &s_ = sec;
		//cout << std::setprecision(50)<<"f: " << f_ << "s: " << s_ << endl;
		reduce(f_, s_);

		result.set_first_data(fir);
		result.set_second_data(sec);
		result.set_data_type(fraction);
		result.set_type(single);
		return result;
	}
}
Compute_data int_fraction_computing_star(Compute_data a, Compute_data b)
{
	Compute_data result;
	Data coe(int_double, 1);
	Compute_data &a_ = a;
	Compute_data &b_ = b;

	result.set_first_data(b.get_first_data()*a.get_first_data());
	result.set_second_data(b.get_second_data());
	double buf = result.get_first_data() / result.get_second_data();
	if (if_int(buf) == true)
	{
		result.set_data_type(int_double);
		result.set_first_data(buf);
		result.set_type(single);
		return result;
	}
	else
	{
		double fir = result.get_first_data();
		double sec = result.get_second_data();
		while ((if_int(fir) == false) || (if_int(sec) == false))
		{
			fir *= 10.0;
			sec *= 10.0;
		}

		double &f_ = fir;
		double &s_ = sec;
		//cout << std::setprecision(50)<<"f: " << f_ << "s: " << s_ << endl;
		reduce(f_, s_);

		result.set_first_data(fir);
		result.set_second_data(sec);
		result.set_data_type(fraction);
		result.set_type(single);
		return result;

	}
	
}


void delete_member(Compute_data &a, int i)
{
	vector<Compute_data>::iterator it;
	int j = 0;
	for (it=a.get_start(); it!=a.get_end(); j++)
	{
		if (j == i)
		{
			it = a.erase(it);
			break;
		}
	}
	return;
}

void reduce_expression(Compute_data &result_)
{
	for (int i = 0; i < result_.get_max_size(); i++)
	{
		vector <Compute_data>::iterator it;
		for (int j = 0; j < result_.get_max_size(); j++)
		{
			if (j != i)
			{
				if (result_.get_the_member(j).get_data_type() == int_double&&result_.get_the_member(i).get_data_type() == int_double)
				{
					Compute_data buf1;
					buf1.set_type(single);
					buf1.set_data_type(int_double);
					buf1.set_first_data(result_.get_the_member(j).get_first_data() + result_.get_the_member(i).get_first_data());
					result_.get_the_member(i) = buf1;
					vector <Compute_data>::iterator it;
					int k = 0;
					for (it = result_.get_start(); it != result_.get_end(); k++)
					{
						if (k == j)
						{
							it = result_.erase(it);
							break;
						}
						else
						{
							it++;
						}

					}

				}
				else if (result_.get_the_member(j).get_data_type() == fraction&&result_.get_the_member(i).get_data_type() == fraction)
				{
					Compute_data buf2 = fraction_computing_plus(result_.get_the_member(j), result_.get_the_member(i));
					result_.get_the_member(i) = buf2;
					vector <Compute_data>::iterator it;
					int k = 0;
					for (it = result_.get_start(); it != result_.get_end(); k++)
					{
						if (k == j)
						{
							it = result_.erase(it);
							break;
						}
						else
						{
							it++;
						}

					}


				}
			}
		}
	}
}

Compute_data compute()
{
	Com_Stack stack;
	for (int i = 0; i <Com_expression.size(); i++)
	{
		if (Com_expression[i].get_data_type() == compute_sign)
		{
			if (stack.get_max_size() < 2)
			{
				print_first_result();
				cout << "your expression is illegal,please enter again!";
				hide_the_last_cursor();
				exit(0);
			}
			else
			{
				Compute_data a;
				Compute_data b;
				b = stack.pop();
				a = stack.pop();
				if (Com_expression[i].get_sign() == plus)
				{
					stack.push(com_plus(a, b));
				}
				else if (Com_expression[i].get_sign() == minus)
				{
					stack.push(com_minus(a, b));
				}
				else if (Com_expression[i].get_sign() == star)
				{
					stack.push(com_star(a, b));
				}
				else if (Com_expression[i].get_sign() == divide)
				{
					stack.push(com_divide(a, b));
				}

			}
		}
		else
		{
			stack.push(Com_expression[i]);
		}
	}
	Compute_data a = stack.pop();
	return a;
}