/*Mitchell Israel
Prof. Croker
CIS 9310
Homework 4
*/

#include <iostream>
using namespace std;

int Prime(int n=0)
{
	int check, value = 0;

	cout << "Enter prime number you want to find: \n";
	cin >> n;

	for (int numerator = 2; numerator <= 10000; numerator++)
	{
		check = 0;

		for (int j = 2; j <= numerator / 2; j++)
		{
			if (numerator % j == 0)
			{
				check = 1;
				break;
			}
		}

		if (check == 0)
			value++;

		if (value == n)
		{
			cout << "The nth prime number, where n is " << n << " is: " << numerator <<"\n\n";
			return true;
		}
	}
}

bool IsPrime(int num)
{
	bool flag;

	cout << "Enter value to be tested: \n";
	cin >> num;
	cout << "\n";

	for (int i = 2; i <= num / 2; i++) {
		if (num % i != 0)
		{
			cout << "This value is prime.\n\n";
			return true;
		}
		else if (false);
		cout << "This value is not prime.\n\n";
	}
}

int main()
{
	do
	{
		char choice;

		cout << "        Menu          \n\n";
		cout << "Enter F to find the nth prime number.\n";
		cout << "Enter T to test a value to see if it is prime.\n";
		cout << "Enter Q to terminate the program.\n";
		cin >> choice;
		choice = choice | 0x20;

		while (choice != 'f' && choice != 't' && choice != 'q')
		{
			cout << "Invalid input\n";
			cin >> choice;
			choice = choice | 0x20;
		}

		if (choice == 'F' || choice == 'f')
			Prime(choice);
		else if (choice == 'T' || choice == 't')
			IsPrime(choice);
		else if (choice == 'Q' || choice == 'q')
			return 0;
	} 
	while (true);
}