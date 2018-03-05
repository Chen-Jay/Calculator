/*
Compute_data result;
Compute_data a, b;
Data coe(int_double, 1);

a.set_type(Mix);
b.set_type(Mix);

Compute_data m1;
m1.set_data_type(int_double);
m1.set_first_data(6);
m1.set_type(single);

Compute_data m2;
m2.set_data_type(fraction);
m2.set_first_data(2);
m2.set_second_data(5);
m2.set_coefficient(coe);
m2.set_type(single);

Compute_data m3;
m3.set_type(single);
m3.set_data_type(fraction);
m3.set_first_data(3);
m3.set_second_data(6);
m3.set_coefficient(coe);

Compute_data m4;
m4.set_type(single);
m4.set_data_type(int_double);
m4.set_first_data(3);

Compute_data m5;
m5.set_type(single);
m5.set_data_type(int_double);
m5.set_first_data(1);

b.push(m1);
b.push(m2);
//b.push(m5);
a.push(m3);
a.push(m4);
//a.push(m5);


result = com_plus(a, b);

if (result.get_type() == single)
{
	if (result.get_data_type() == fraction)
	{
		cout << "result= " << setprecision(15) << result.get_first_data() << "/" << result.get_second_data() << endl << result.get_first_data() / result.get_second_data();
	}
	else
	{
		cout << setprecision(15) << "result:" << result.get_first_data() << endl;
	}
}
else
{
	for (int i = 0; i < result.get_max_size(); i++)
	{
		cout << result.get_max_size();
		if (result.get_the_member(i).get_data_type() == fraction)
		{
			cout << "the " << i << "th result= " << setprecision(50) << result.get_the_member(i).get_first_data() << "/" << result.get_the_member(i).get_second_data() << endl;
		}
		else
		{
			cout << "the " << i << "th result= " << setprecision(50) << result.get_the_member(i).get_first_data() << endl;
		}
	}
}
*/