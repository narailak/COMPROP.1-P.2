#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

char findGrade(double x)
{
	char z[5] = {'A', 'B', 'C', 'D', 'F'};
	if (x > 90)
		return z[0];
	else if (x > 75 && x <= 90)
		return z[1];
	else if (x > 60 && x <= 75)
		return z[2];
	else if (x > 45 && x <= 60)
		return z[3];
	else
		return z[4];
}

int main()
{
	// Input the number of students
	int N, i = 0;
	cout << "Enter the number of students: ";
	cin >> N;
	string name[N];
	float score[N];

	// Store names and scores of students into an array
	while (i < N)
	{
		cout << "Name of student " << i + 1 << ": ";
		cin.ignore();
		getline(cin, name[i]);
		cout << "Score of student " << i + 1 << ": ";
		cin >> score[i];
		i++;
	}

	// Print names scores and grades
	i = 0;
	cout << "---------------------------------------------\n";
	cout << setw(25) << "Name" << setw(8) << "Score" << setw(8) << "Grade"
		 << "\n";
	cout << "---------------------------------------------\n";
	while (i < N)
	{
		cout << setw(25) << name[i] << setw(8) << score[i] << setw(8) << findGrade(score[i]) << "\n";
		i++;
	}
	cout << "---------------------------------------------\n";

	return 0;
}