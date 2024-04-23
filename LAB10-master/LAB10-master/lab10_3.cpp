#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    int count = 0;
    double sum, sumoqr, mean, std;
    string textline;
    ifstream source("score.txt");
    while (getline(source, textline))
    {
        sum += atof(textline.c_str());
        sumoqr += pow(atof(textline.c_str()), 2);
        count++;
    }
    mean = sum / count;
    std = sqrt(sumoqr / count - pow(mean, 2));

    cout << "Number of data = " << count << "\n";
    cout << setprecision(3);
    cout << "Mean = " << mean << "\n";
    cout << "Standard deviation = " << std;
}