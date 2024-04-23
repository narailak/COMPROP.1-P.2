#include <iostream>
using namespace std;

int main()
{
	int nA, nB;
	int *A, *B, **C;

	cout << "Length of A: ";
	cin >> nA;

	A = new int[nA];
	cout << "Input Array A: ";
	for (int i = 0; i < nA; i++)
		cin >> A[i];

	cout << "Length of B: ";
	cin >> nB;

	B = new int[nB];
	cout << "Input Array B: ";
	for (int i = 0; i < nB; i++)
		cin >> B[i];

	C = new int *[nA];
	for (int i = 0; i < nA; i++)
		C[i] = new int[nB];

	for (int i = 0; i < nA; i++)
	{
		for (int j = 0; j < nB; j++)
		{
			C[i][j] = A[i] * B[j];
		}
	}

	cout << "\t";
	for (int i = 0; i < nB; i++)
	{
		cout << B[i] << "\t";
	}
	cout << "\n-----------------------------\n";

	for (int i = 0; i < nA; i++)
	{
		cout << A[i] << "\t";
		for (int j = 0; j < nB; j++)
		{
			cout << C[i][j] << "\t";
		}
		cout << "\n";
	}
	for (int i = 0; i < nA; i++)
		delete[] C[i];
	delete[] A;
	delete[] B;
	delete[] C;
	return 0;
}