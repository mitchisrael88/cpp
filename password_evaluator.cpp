/*Mitchell Israel
Prof.Croker
CIS 9310
Programming Assignment 5
*/

#include <iostream>
using namespace std;

//declare functions
int PWRating(char pw[]);
bool UpperChar(char pw[]);
bool LowerChar(char pw[]);
bool DigitChar(char pw[]);
bool specialChar(char pw[]);
bool MoreData();



int main()
{
	char initial, testPassword[100];
	int count, ratings[5] = { 0, 0, 0, 0, 0 };
	string score;
	cout << "Would you like to enter a passowrd for evaluation (Y/N):\n";
		cin >> initial;
		//validate userResponse value
		initial |= 0x20;        //convert initial response to lowercase
		do{
			if (initial == 'y' || initial == 'Y')
			{
				cout << "Enter password to be tested: \n";
				cin >> testPassword;
				count = PWRating(testPassword);
					if (count == 5) {
						score = "Best";
						cout << "Password is " << score <<endl;
					}
					else if (count == 4) {
						score = "Good";
						cout << "Password is " << score << endl;
					}
					else if (count == 3) {
						score = "Weak";
						cout << "Password is " << score << endl;
					}
					else if (count == 2) {
						score = "Poor";
						cout << "Password is " << score << endl;
					}
					else {
						score = "Unacceptable\n";
						cout << "Password is " << score << endl;
					}
					ratings[count-1]++;
					
			}
					

			else if ((initial != 'y' || initial != 'Y') || (initial != 'n' || initial != 'N'))
			{
			cout << "Invalid response. ";
			}
		else return false;
				
	} while (MoreData());
		
	cout << "Passwords with Best rating : " << ratings[4];
	cout << "\nPasswords with Good rating : " << ratings[3];
	cout << "\nPasswords with Weak rating : " << ratings[2];
	cout << "\nPasswords with Poor rating : " << ratings[1];
	cout << "\nPasswords with Unacceptable rating : " << ratings[0];
	
}

int PWRating(char pw[])
{
	int count=0;
	
		if (strlen(pw) >=8)
			count++;
		if (UpperChar(pw))
			count++;
		if (LowerChar(pw))
			count++;
		if (DigitChar(pw))
			count++;
		if (specialChar(pw))
			count++;
	return count;
}
	
bool LowerChar(char pw[]) {
	for (unsigned int i = 0; i < strlen(pw); i++) {
		if (islower(pw[i])) {
			return true;
			break;
		}
	}
	return false;
}
	

bool UpperChar(char pw[]) {
	for (unsigned int i = 0; i < strlen(pw); i++) {
		if (isupper(pw[i])) {
			return true;
			break;
		}
	}
	return false;
}


bool DigitChar(char pw[]) {
	for (unsigned int i = 0; i < strlen(pw); i++) {
		if (isdigit(pw[i])) {
			return true;
			break;
		}
	}
	return false;
}

bool specialChar(char pw[]) {
	bool specialChar = true;
	for (unsigned int i = 0; i < strlen(pw); i++) {
		if (isdigit(pw[i]) || isalpha(pw[i]))
			specialChar = false;
		else {
			specialChar = true;
			break;
		}
	}
	if (specialChar == true)
		return true;
	else
		return false;
}

bool MoreData()
{
	char userResponse;

	cout << "Would you like to test another password? (Y/N): \n";
	cin >> userResponse;

	//validate userResponse value
	userResponse |= 0x20;        //convert repeat response to lowercase

	//execute loop until a value value for userResponse has been input
	while ((userResponse != 'y') && (userResponse != 'n')) {
		cout << "Invalid response, enter Y or N: ";
		cin >> userResponse;
		userResponse |= 0x20;    //convert repeat response to lowercase
	}

	return (userResponse == 'y');
}