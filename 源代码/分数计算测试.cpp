/*
Compute_data result;
Compute_data a, b;
a.set_type(single);
b.set_type(single);
a.set_data_type(fraction);
b.set_data_type(fraction);

a.set_first_data(2.41595625);
b.set_first_data(3.333333333335);
a.set_second_data(5);
b.set_second_data(5);
*/

/*{if (a.get_second_data() == b.get_second_data())
{
	result.set_first_data(a.get_first_data() + b.get_first_data());
	result.set_second_data(a.get_second_data());
	double buf = result.get_first_data() / result.get_second_data();
	if (if_int(buf) == true)
	{
		result.set_data_type(int_double);
		result.set_first_data(buf);
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
		reduce(f_, s_);

		result.set_first_data(fir);
		result.set_second_data(sec);
		result.set_data_type(fraction);
	}
}
else
{
	a.set_first_data(a.get_first_data()*b.get_second_data());
	b.set_first_data(b.get_first_data()*a.get_second_data());
	a.set_second_data(a.get_second_data()*b.get_second_data());
	b.set_second_data(a.get_second_data());
	cout << "a= " << setprecision(15) << a.get_first_data() << "/" << a.get_second_data() << endl;
	cout << "b= " << setprecision(15) << b.get_first_data() << "/" << b.get_second_data() << endl;
	double fir = a.get_first_data() + b.get_first_data();
	double sec = a.get_second_data();
	if (fir == sec)
	{
		result.set_data_type(int_double);
		result.set_first_data(1);
	}
	else
	{
		double buf = fir / sec;
		if (if_int(buf) == true)
		{
			result.set_data_type(int_double);
			result.set_first_data(buf);
		}
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
			}
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
				result.set_first_data(fir);
				result.set_second_data(sec);
				result.set_data_type(fraction);
			}

		}
	}

}
}
*/

/*
if (result.get_data_type() == fraction)
cout << "result= " << setprecision(50) << result.get_first_data() << "/" << result.get_second_data() << endl << result.get_first_data() / result.get_second_data();
else
{
	cout << setprecision(50) << "result:" << result.get_first_data() << endl;
}
*/