#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int data[] = {7,8,2,1,2,4,6,9,0,1}; 
	cout << "Before: ";
	for(int i = 0; i<10; i++) cout << data[i] << " ";
	sort(&data[0],&data[5]);
	sort(&data[5],&data[10]);
	cout << "\nAfter: ";
	for(int i = 0; i<10; i++) cout << data[i] << " ";
	return 0;
}