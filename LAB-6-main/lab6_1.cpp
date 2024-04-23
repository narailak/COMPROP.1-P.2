#include<iostream>
using namespace std;

int main(){
    int n, a = 0 , b=0;
    cout << "Enter an integer: ";
    cin >> n;
    while (n != 0)
    {
        if (n%2 == 0)
        {
         a++;
        }else{
        b++;
        }
        cout << "Enter an integer: ";
        cin >> n;
    }
    
    cout << "#Even numbers = " << a << endl ;
    cout << "#Odd numbers = " << b;

    return 0;
}
