#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int a[] = {1,2,4,6,9}; 
	double b[] = {5.5,2.1,13,-7,6.9,0,25,11.1,-4}; 
	
	int *pa = max_element(&a[0],&a[5]); 
	cout << "Address of the highest value in array A is " << pa << "\n";
	cout << "The highest value in array A is "<< *pa << "\n";
	
	double *pb = max_element(&b[0],&b[9]); 
	cout << "Address of the highest value in array B is " << pb << "\n";
	cout << "The highest value in array B is "<< *pb << "\n";

	return 0;
}