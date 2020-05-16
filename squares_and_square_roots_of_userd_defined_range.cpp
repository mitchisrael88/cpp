#include <iostream>
using namespace std;
//Produce a Table with Squares and Square Roots of User Defined Range

double Power(double base, int exponent)
{
	double result=1, n=0;
	if (exponent > 0)
	{
		for (int n = 0; n <= exponent; n++)
			result = base * base;
	}
	return result;
}

double Sqrt(double NewValue)
{
	double N = NewValue, OldValue, error = abs(0.005);
	
	while ((NewValue - N/ NewValue) > error) 
	{
	OldValue = NewValue;
	NewValue = ((OldValue + N / OldValue) / 2);
	}
	return NewValue;
}

bool MoreData()
{
	char choice;
	

	cout << "Would you like to enter another range of values?\n";
	cin >> choice;
	choice = choice | 0x20;

	while (choice != 'y' && choice != 'n')
	{
		cout << "Invalid response, please enter \"Y\" or \"N\": \n";
		cin >> choice;
		choice = choice | 0x20;
	}

	if (choice == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	//establish variables
	double LowerLimit, UpperLimit, Exp, Squares;
	char choice;

	cout << "Mitchell Israel\nProf.Croker\nCIS 9310\nHomework 3\n\n";

	//explain program to user
	cout << "This program produces a table with squares and square roots of user defined range.\n";

	do
	{
		//prompt user to enter values
		cout << "Enter lower limit: \n";
		cin >> LowerLimit;
		cout << "\n";

		cout << "Enter upper limit: \n";
		cin >> UpperLimit;
		cout << "\n";

		//prompt user to enter power for 2nd column of table
		cout << "Enter power bases will be raised to:\n";
		cin >> Exp;
		cout << "\n\n";

		//If lower limit is larger than upper limit, reverse inputs
		double temp;

		if (LowerLimit > UpperLimit)
		{
			temp = LowerLimit;
			LowerLimit = UpperLimit;
			UpperLimit = temp;
		}

		cout << "N\tN Squared\tSquare Root (N)\n";

		for (LowerLimit; LowerLimit <= UpperLimit; LowerLimit++)
		{
			//output values in table
			cout << LowerLimit << "\t" << Power(LowerLimit, UpperLimit) << "\t\t" << Sqrt(LowerLimit) <<"\n";
				;
		}

	}
	while (MoreData());
}