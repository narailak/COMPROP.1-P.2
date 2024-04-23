#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[], int, double[]);

int main()
{
    double A[] = {1.2, 3.5, 6.9, 7.8, 12.5, 0.5};
    int N = sizeof(A) / sizeof(A[0]);
    double B[6];
    stat(A, N, B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[], int N, double B[])
{
    double sum = 0, sumsquare = 0, mix = 1, sumhar = 0;
    double AM, GM, SD, HM, MAX = -9999999999999, MIN = 999999999999;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
        sumsquare += pow(A[i], 2);
        mix *= A[i];
        sumhar += 1 / A[i];
        if (A[i] > MAX)
            MAX = A[i];
        if (A[i] < MIN)
            MIN = A[i];
    }
    AM = sum / N;
    B[0] = AM;
    SD = sqrt((sumsquare / N) - (pow(AM, 2)));
    B[1] = SD;
    GM = pow(mix, 1.0 / N);
    B[2] = GM;
    HM = N / sumhar;
    B[3] = HM;
    B[4] = MAX;
    B[5] = MIN;
}