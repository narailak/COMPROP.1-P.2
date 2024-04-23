#include <iostream>
#include <iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main()
{
	double loan, per_year, amount;
	cout << "Enter initial loan: ";
	cin >> loan;
	cout << "Enter interest rate per year (%): ";
	cin >> per_year;
	cout << "Enter amount you can pay per year: ";
	cin >> amount;

	// use 'setw' to set width of table and 'left' to set left-alignment
	// you can change input argument of 'setw()' to see the effect
	// Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#";
	cout << setw(13) << left << "PrevBalance";
	cout << setw(13) << left << "Interest";
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";

	double NewBalance = loan, Interest, Total;
	// use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	// you can change input argument of 'setprecision()' to see the effect
	for (int i = 1; NewBalance != 0; i++)
	{
		Interest = (NewBalance * per_year) / 100;
		Total = NewBalance + Interest;

		cout << fixed << setprecision(2);
		cout << setw(13) << left << i;
		cout << setw(13) << left << NewBalance;
		cout << setw(13) << left << Interest;
		cout << setw(13) << left << Total;

		if (NewBalance >= 100 && Total > amount)
		{
			NewBalance = Total - amount;
			cout << setw(13) << left << amount;
		}
		else
		{
			amount = Total;
			cout << setw(13) << left << amount;
			NewBalance = Total - amount;
		}
		cout << setw(13) << left << NewBalance;
		cout << "\n";
	}

	return 0;
}