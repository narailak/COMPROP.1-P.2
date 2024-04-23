#include <iostream>
using namespace std;

int main(){

int a = 5;
char b = 'A'; 
char &c = b;
int *x = &a;
char *y = &b; 
int **z = &x;

cout << a << " ";
cout << b << " ";
cout << c << " ";
cout << x << " ";
cout << &y << " ";
cout << z << " " << endl;

cout << &a << " ";
cout << x << " ";
cout << x << " ";
cout << &x << " ";
cout << &y << " ";
cout << &z << " " << endl;

c = 'F';

cout << a << " ";
cout << b << " ";
cout << c << " ";
cout << x << " ";
cout << &y << " "; 
cout << z << " " << endl;

*y = 'W';

cout << a << " ";
cout << b << " ";
cout << c << " ";
cout << x << " ";
cout << &y << " ";
cout << z << " " << endl;

*x = 6;

cout << a << " ";
cout << b << " ";
cout << c << " ";
cout << x << " ";
cout << &y << " ";
cout << z << " " << endl;

**z = 7;

cout << a << " ";
cout << b << " ";
cout << c << " ";
cout << x << " ";
cout << &y << " ";
cout << z << " " << endl;


return 0;
}