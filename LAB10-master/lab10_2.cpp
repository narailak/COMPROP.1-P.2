#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string textline;
	ifstream source;
	ofstream dest;
	source.open("cheerbook.txt");
	dest.open("cheerbook_copy.txt");

	dest << "-------------------- BOOM ---------------------" << endl;
	while (getline(source, textline))
	{
		dest << textline << endl;
	}
	dest << "-------------------- HA!! ---------------------";
	source.close();
	dest.close();
	return 0;
}