#include <iostream>
using namespace std;
//Prime Number Generator within User Defined Range

int main()
{
	//establish variables
	int LowerLimit, UpperLimit, i, j;

	//prompt user to enter values
	cout << "Enter lower limit: \n";
	cin >> LowerLimit;

	cout << "Enter upper limit: \n";
	cin >> UpperLimit;

	//output values in statement
	cout << "The prime numbers between " << LowerLimit << " and " << UpperLimit << " are: ";

	//loop to produce list of prime values in range
	while (LowerLimit < UpperLimit)
	{
		j = 0;

		for (i = 2; i <= LowerLimit / 2; ++i)
		{
			if (LowerLimit % i == 0)
			{
				j = 1;
				break;
			}
		}

		if (j == 0)
			cout << LowerLimit << " " ;

		++LowerLimit;
	}
	cout << " ";
}

