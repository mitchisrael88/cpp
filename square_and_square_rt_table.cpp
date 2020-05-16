/*Mitchell Israel
Prof.Croker
CIS 9310
Programming Assignment 4
*/


#include <iostream>
using namespace std;

//function declarations:
double Power(double base, int exp);
double Sqrt(double NewValue);
int GetData(double list[100]);
void Sort(double list[100], int count, char order);

int main()
{
	// an int array 
	double testArray[100], count;
	int init = 0, exp;
	char order;

	//provide number of values for the array
	count = GetData(testArray);
	
	cout << "How would you like to sort the array, ascending or descending?\n";
	cin >> order;
	
	//Call Sort function
	Sort(testArray, count, order);

	//output table headers
	cout << "\nN\tN-Squared\tSquare Root (N)\n";

	//output table values
	for (testArray; init < count; init++)
	{
		cout << "\n" << testArray[init] << "\t" << Power(testArray[init], exp = 2) << "\t\t" << Sqrt(testArray[init]) << "\n";
	}
}

double Power(double base, int exp)
{
	//initialize local variables
	double result = 1;

	//account for negative exponent
	if (exp < 0) 
	{
		exp = -exp;
		base = 1 / base;
	}

	//raise value to assigned power
	for (int i = 0; i < exp; i++)
		result *= base;

	return result;
}


double Sqrt(double NewValue)
{
	//initialize local variables
	double N = NewValue, OldValue, error = 0.005;

	//produce square root of value
	while ((NewValue - N / NewValue) > abs(error))
	{
		OldValue = NewValue;
		NewValue = ((OldValue + N / OldValue) / 2);
	}
	return NewValue;
}

int GetData(double list[100])
{
	int test, length = 0;
	
	//user determined length of array
	cout << "How many values would you like in the array?\n";
	cin >> length;

	//create array from used entered values
	for (test = 0; test < length; test++)
	{
		cout << "Enter value for array:\n";
		cin >> list[test];
	}
	return length;
}

void Sort(double list[100], int count, char order)
{
	
	int x, y, flag = 1;
	double temp;

	//sort descending
	if (order == 'D' || order == 'd') 
	{
		for (x = 1; (x <= count) && flag; x++) 
		{
			flag = 0;
			for (y = 0; y < (count - 1); y++)
			{
				if (list[y + 1] > list[y])
				{
					temp = list[y];
					list[y] = list[y + 1];
					list[y + 1] = temp;
					flag = 1;
				}
			}
			
		}
	}
	else   //sort ascending
	{
		for (x = 1; (x < count) && flag; x++)
		{
			flag = 0;
			for (y = 0; y < (count - 1); y++)
			{
				if (list[y + 1] < list[y])
				{
					temp = list[y];
					list[y] = list[y + 1];
					list[y + 1] = temp;
					flag = 1;
				}
			}

		}
	}
}