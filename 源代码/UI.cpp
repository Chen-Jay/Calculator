#include "UI.h"
#include "compute.h"
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

void presetting()
{
	console.setWindowSize(150, 40);
	console.setTextColor(ColorType::INDIGO, true);
}
void print_title()
{
	console.moveCursorTo(21, 3); cout << "                       *******              *               *";
	console.moveCursorTo(21, 4); cout << "                      *                    * *              *";
	console.moveCursorTo(21, 5); cout << "                     *                    *   *             *";
	console.moveCursorTo(21, 6); cout << "                    *                    * * * *            *";
	console.moveCursorTo(21, 7); cout << "                     *                  *       *           *";
	console.moveCursorTo(21, 8); cout << "                      *                *         *          *";
	console.moveCursorTo(21, 9); cout << "                       *******        *           *         * * * * * ";
	console.moveCursorTo(21, 13); cout << "        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
	console.moveCursorTo(21, 14); cout << "        *                                                                       * ";
	console.moveCursorTo(21, 15); cout << "        *                                                                       *";
	console.moveCursorTo(21, 16); cout << "        *                                                                       * ";
	console.moveCursorTo(21, 17); cout << "        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
	
	console.moveCursorTo(31, 15);
}

void print_first_result()
{
	console.moveCursorTo(21, 19); cout << "        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
	console.moveCursorTo(21, 20); cout << "        *                                                                       *";
	console.moveCursorTo(21, 21); cout << "        *                                                                       *";
	console.moveCursorTo(21, 22); cout << "        *                                                                       *";
	console.moveCursorTo(21, 23); cout << "        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";

	console.moveCursorTo(31, 21);
	
}

void print_first_result(Compute_data result)
{
	console.moveCursorTo(21, 19); cout << "        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
	console.moveCursorTo(21, 20); cout << "        *                                                                       *";
	console.moveCursorTo(21, 21); cout << "        *                                                                       *";
	console.moveCursorTo(21, 22); cout << "        *                                                                       *";
	console.moveCursorTo(21, 23); cout << "        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";

	console.moveCursorTo(31, 21);
	show_the_result(result);
}

void print_second_result(Compute_data result)
{
	console.moveCursorTo(21, 30); cout << "        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
	console.moveCursorTo(21, 31); cout << "        *                                                                       *";
	console.moveCursorTo(21, 32); cout << "        *                                                                       *";
	console.moveCursorTo(21, 33); cout << "        *                                                                       *";
	console.moveCursorTo(21, 34); cout << "        *                                                                       *";
	console.moveCursorTo(21, 35); cout << "        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";

	int x, y;
	while (true)
	{
		if (console.mouseOperation(x, y) == true && (x > 33 && x < 45) && (y > 25 && y < 28))
		{
			console.moveCursorTo(21, 30); cout << "        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
			console.moveCursorTo(21, 31); cout << "        *                                                                       *";
			console.moveCursorTo(21, 32); cout << "        *                                                                       *";
			console.moveCursorTo(21, 33); cout << "        *                                                                       *";
			console.moveCursorTo(21, 34); cout << "        *                                                                       *";
			console.moveCursorTo(21, 35); cout << "        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";

			console.moveCursorTo(17, 25); cout << "                * * * * * * *        * * * * * * * *        * * * * * * * ";
			console.moveCursorTo(17, 26); cout << "                * fraction  *        *  fraction   *        *   value   *";
			console.moveCursorTo(17, 27); cout << "                *           *        *  &integer   *        *           *";
			console.moveCursorTo(17, 28); cout << "                * * * * * * *        * * * * * * * *        * * * * * * *";

			console.setTextColor(ColorType::GREEN, true);
			console.moveCursorTo(33, 25); cout << "* * * * * * *";
			console.moveCursorTo(33, 26); cout << "* fraction  *";
			console.moveCursorTo(33, 27); cout << "*           *";
			console.moveCursorTo(33, 28); cout << "* * * * * * *";

			console.moveCursorTo(31, 33);
			show_the_result_fra(result);
			console.setTextColor(ColorType::INDIGO, true);
		}
		else if (console.mouseOperation(x, y) == true && (x > 54 && x < 68) && (y > 25 && y < 28))
		{
			console.moveCursorTo(17, 25); cout << "                * * * * * * *        * * * * * * * *        * * * * * * * ";
			console.moveCursorTo(17, 26); cout << "                * fraction  *        *  fraction   *        *   value   *";
			console.moveCursorTo(17, 27); cout << "                *           *        *  &integer   *        *           *";
			console.moveCursorTo(17, 28); cout << "                * * * * * * *        * * * * * * * *        * * * * * * *";

			console.moveCursorTo(21, 30); cout << "        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
			console.moveCursorTo(21, 31); cout << "        *                                                                       *";
			console.moveCursorTo(21, 32); cout << "        *                                                                       *";
			console.moveCursorTo(21, 33); cout << "        *                                                                       *";
			console.moveCursorTo(21, 34); cout << "        *                                                                       *";
			console.moveCursorTo(21, 35); cout << "        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";

			console.setTextColor(ColorType::YELLOW, true);
			console.moveCursorTo(54, 25); cout << "* * * * * * * *";
			console.moveCursorTo(54, 26); cout << "*  fraction   *";
			console.moveCursorTo(54, 27); cout << "*  &integer   *";
			console.moveCursorTo(54, 28); cout << "* * * * * * * *";

			console.moveCursorTo(31, 33);
			show_the_result_fra_int(result);

			console.setTextColor(ColorType::INDIGO, true);
		}
		else if (console.mouseOperation(x, y) == true && (x > 77 && x < 89) && (y > 25 && y < 28))
		{
			console.moveCursorTo(17, 25); cout << "                * * * * * * *        * * * * * * * *        * * * * * * * ";
			console.moveCursorTo(17, 26); cout << "                * fraction  *        *  fraction   *        *   value   *";
			console.moveCursorTo(17, 27); cout << "                *           *        *  &integer   *        *           *";
			console.moveCursorTo(17, 28); cout << "                * * * * * * *        * * * * * * * *        * * * * * * *";

			console.moveCursorTo(21, 30); cout << "        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
			console.moveCursorTo(21, 31); cout << "        *                                                                       *";
			console.moveCursorTo(21, 32); cout << "        *                                                                       *";
			console.moveCursorTo(21, 33); cout << "        *                                                                       *";
			console.moveCursorTo(21, 34); cout << "        *                                                                       *";
			console.moveCursorTo(21, 35); cout << "        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";

			console.setTextColor(ColorType::PURPLE, false);
			console.moveCursorTo(77, 25); cout << "* * * * * * *";
			console.moveCursorTo(77, 26); cout << "*   value   *";
			console.moveCursorTo(77, 27); cout << "*           *";
			console.moveCursorTo(77, 28); cout << "* * * * * * *";

			console.moveCursorTo(31, 33);
			show_the_result_val(result);

			console.setTextColor(ColorType::INDIGO, true);
		}
	}
}

void print_the_buttons()
{
	console.moveCursorTo(17, 25); cout << "                * * * * * * *        * * * * * * * *        * * * * * * * ";
	console.moveCursorTo(17, 26); cout << "                * fraction  *        *  fraction   *        *   value   *";
	console.moveCursorTo(17, 27); cout << "                *           *        *  &integer   *        *           *";
	console.moveCursorTo(17, 28); cout << "                * * * * * * *        * * * * * * * *        * * * * * * *";

}

void hide_the_last_cursor()
{
	console.moveCursorTo(0, 0);
	console.setTextColor(ColorType::BLACK, true);
	console.hideCursor();
}


void show_the_result_fra_int(Compute_data result)
{
	if (result.get_type() == single)
	{
		if (result.get_data_type() == fraction)
		{
			int integer = long long (result.get_first_data()) / long long(result.get_second_data());
			long long  frac = result.get_first_data() - integer*result.get_second_data();
			cout << setprecision(20) << integer << "+" << frac << "/" << result.get_second_data();
		}
		else if (result.get_data_type() == int_double)
		{
			if (if_int(result.get_first_data()) == true)
			{
				cout << setprecision(20) << result.get_first_data() << endl;
			}
			else
			{
				result.set_data_type(fraction);
				result.set_second_data(1);
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
				
				int integer = long int(result.get_first_data()) / long int(result.get_second_data());
				int frac = result.get_first_data() - integer*result.get_second_data();
				cout << setprecision(20) << integer << "+" << frac << "/" << result.get_second_data();
			}
		}
		else if (result.get_data_type() == compute_sign)
		{
			cout << result.get_sign_text() << endl;
		}
	}
	else
	{
		for (int i = 0; i < result.get_max_size(); i++)
		{
			cout << result.get_max_size();
			if (result.get_the_member(i).get_data_type() == fraction)
			{
				cout << setprecision(20) << result.get_the_member(i).get_first_data() << "/" << result.get_the_member(i).get_second_data();
			}
			else
			{
				cout << setprecision(20) << result.get_the_member(i).get_first_data() << endl;
			}
			if (i != result.get_max_size() - 1)
			{
				cout << " + ";
			}
		}
	}

}

void show_the_result_fra(Compute_data result)
{
	if (result.get_type() == single)
	{
		if (result.get_data_type() == fraction)
		{
			cout << setprecision(20) << result.get_first_data() << "/" << result.get_second_data() << endl;
		}
		else if (result.get_data_type() == int_double)
		{
			result.set_data_type(fraction);
			result.set_first_data(result.get_first_data());
			result.set_second_data(1);
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

			cout << result.get_first_data() << "/" << result.get_second_data() << endl;
		}
		else if (result.get_data_type() == compute_sign)
		{
			cout << result.get_sign_text() << endl;
		}
	}
	else
	{
		for (int i = 0; i < result.get_max_size(); i++)
		{
			cout << result.get_max_size();
			if (result.get_the_member(i).get_data_type() == fraction)
			{
				cout << setprecision(20) << result.get_the_member(i).get_first_data() << "/" << result.get_the_member(i).get_second_data() << endl;
			}
			else
			{
				cout << setprecision(20) << result.get_the_member(i).get_first_data() << endl;
			}
		}
	}

}

void show_the_result_val(Compute_data result)
{
	if (result.get_type() == single)
	{
		if (result.get_data_type() == fraction)
		{
			cout << setprecision(15) << result.get_first_data()/ result.get_second_data();
		}
		else if (result.get_data_type() == int_double)
		{
			cout << setprecision(15) << result.get_first_data();
		}
		else if (result.get_data_type() == compute_sign)
		{
			cout << result.get_sign_text();
		}
	}
	else
	{
		for (int i = 0; i < result.get_max_size(); i++)
		{
			cout << result.get_max_size();
			if (result.get_the_member(i).get_data_type() == fraction)
			{
				cout << setprecision(20) << result.get_the_member(i).get_first_data()/ result.get_the_member(i).get_second_data();
			}
			else
			{
				cout << setprecision(20) << result.get_the_member(i).get_first_data();
			}
			if (i != result.get_max_size() - 1)
			{
				cout << " + ";
			}
		}
	}

}

void show_the_result(Compute_data result)
{
	if (result.get_type() == single)
	{
		if (result.get_data_type() == fraction)
		{
			cout << setprecision(15) << result.get_first_data() << "/" << result.get_second_data() << endl;
		}
		else if (result.get_data_type() == int_double)
		{
			cout << setprecision(15) << result.get_first_data() << endl;
		}
		else if (result.get_data_type() == compute_sign)
		{
			cout << result.get_sign_text() << endl;
		}
	}
	else
	{
		for (int i = 0; i < result.get_max_size(); i++)
		{
			cout << result.get_max_size();
			if (result.get_the_member(i).get_data_type() == fraction)
			{
				cout << setprecision(15) << result.get_the_member(i).get_first_data() << "/" << result.get_the_member(i).get_second_data() << endl;
			}
			else
			{
				cout << setprecision(15) << result.get_the_member(i).get_first_data() << endl;
			}
		}
	}

}
