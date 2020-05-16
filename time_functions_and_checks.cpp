/*Mitchell Israel
CIS 9310
Prof. Croker
Programming Assignment 7*/

#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
	int hour, minute, seconds;
		
	public: 
		Time() : hour(0), minute(0), seconds(0) {}  // default constructor
		Time(int h, int m = 0, int s = 0) {
			hour = h;
			minute = m;
			seconds = s;

		}

		void setHours(int h)
		{
			hour = h;
		}
		
		void setMinutes(int m)
		{
			minute = m;
		}
		
		void setSeconds(int s)
		{
			seconds = s;
		}

		void setTime(int h, int m, int s)
		{
			hour = h;
			minute = m;
			seconds = s;
		}

		int getHours() const
		{
			return hour;
		}

		int getMinutes() const
		{
			return minute;
		}

		int getSeconds() const
		{
			return seconds;
		}

		bool LessThan(Time t)
		{
			if (hour < t.hour)
				return true;
			else if (hour == t.hour && minute < t.minute)
				return true;
			else if (hour == t.hour && minute == t.minute && seconds < t.seconds)
				return true;
			else return false;
		}

		bool GreaterThan(Time t)
		{
			if (hour > t.hour)
				return true;
			else if (hour == t.hour && minute > t.minute)
				return true;
			else if (hour == t.hour && minute == t.minute && seconds > t.seconds)
				return true;
			else return false;
		}

		bool EqualTo(Time t)
		{
			if (hour == t.hour && minute == t.minute && seconds == t.seconds)
				return true;
			else return false;
		}

		void Read()
		{
			cout << "Enter time value: ";
			char skip;
			cin >> hour >> skip >> minute >> skip >> seconds;
		}

		void Write()
		{
			cout << hour << ":";
			if (minute < 10)
				cout << "0" << minute;
			else cout << minute;
			if (seconds < 10)
				cout << ":0" << seconds;
			else cout << ":" << seconds;
		}
};

void Sort(Time list[100], int count)
{

	int x, y, flag = 1;
	Time temp;

	//sort ascending
	for (x = 1; (x < count) && flag; ++x)
		{
			flag = 0;
			for (y = 0; y < (count - 1); y++)
			{
				if (list[y].GreaterThan(list[y+1]))
				{
					temp = list[y];
					list[y] = list[y + 1];
					list[y + 1] = temp;
					flag = 1;
				}
			}
	}
	
}

int main()
{

	Time testArray[100];
	int count;
	int init = 0;
	Time t;

	//get number of values in array
	cout << "How many values of time would you like to process? ";
	cin >> count;

	//provide values for the time array
	for (int i = 0; i < count; i++) 
		{
		t.Read();
		testArray[i] = t;
		}
		
	//Call Sort function
	Sort(testArray, count);

	for (int i = 0; i < count; i++)
	{
		cout << "\n";
		testArray[i].Write();
	}

	
	Time tm1,                   //test default constructor
		tm2(10, 20, 30),         //test initialization constructor
		tm3(14);

	cout << "\n\nValues of tm1, tm2 and tm3 on same line\ntm1 = ";
	tm1.Write();
	cout << "\ttm2 = ";
	tm2.Write();
	cout << "\ttm3 = ";
	tm3.Write();

	tm3.setTime(21, 28, 35);
	cout << "\n\nThe value of tm3 is now ";
	tm3.Write();

	tm3.setHours(5);
	tm3.setMinutes(15);
	tm3.setSeconds(25);

	cout << "\n\nThe value of tm3 is now " << tm3.getHours()
		<< " hours, " << tm3.getMinutes() << " minutes and "
		<< tm3.getSeconds() << " seconds" << endl;

	tm1 = tm3;
	cout << "\nValues of tm1, tm2, and tm3 are now\ntm1 = ";
	tm1.Write();
	cout << "\ttm2 = ";
	tm2.Write();
	cout << "\ttm3 = ";
	tm3.Write();

	cout << boolalpha << endl;
	cout << tm2.LessThan(tm3) << '\t' << tm2.GreaterThan(tm3) << '\t'
		<< tm2.EqualTo(tm3) << '\t' << tm1.EqualTo(tm3) << '\n';

	cout << "\n\nEnter the following Time value 14:15:16: ";
	tm1.Read();
	cout << "\nThe value entered is ";
	tm1.Write();

	cout << endl;

	return 0;
}