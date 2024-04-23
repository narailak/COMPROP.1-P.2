#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    string grade [] = {"A","B+","B","C+","C","D+","D","F","W"};
    int i = rand() %9;
    cout << "Press Enter 3 times to reveal your future.";
    for(int b =0;b< 3;b++)
    {
        cin.get();
    }
    cout << "You will get " << grade[i] <<" in this 261102.";
}