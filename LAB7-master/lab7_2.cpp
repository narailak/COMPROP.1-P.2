#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string t1,t2,t3;
int x;
int main(){
    cout<<"Fahsai: Sawadee ka...Can you tell me your name?\n";
    cout<<"?????: ";
    getline(cin,t1);
    cout<<"Fahsai: Wow!!! "<<t1<<" is a really cool name.\n";
    cout<<"Fahsai: I think you are an Engineering student. What is your student ID?\n";
    cout<<t1<<": ";
    cin>>x;
    cout<<"Fahsai: I think you may be GEAR "<<(x/(10000000))-12<<". I have a free movie ticket for you.\n";
    cout<<"Fahsai: Let's go to the cinema together!!!\n";
    cout<<"Fahsai: What movie do you want to watch?\n";
    cout<<t1<<": ";
    cin.ignore();
    getline(cin,t2);
    cout<<"Fahsai: So....which day are you free to go with me?\n";
    cout<<t1<<": ";
    getline(cin,t3);
    cout<<"Fahsai: "<<t3<<"....that is OK!!! I'm looking forward to watching "<<t2<<" with you.\n";
    cout<<t1<<": ";
    cin.ignore();
    cout<<"Fahsai: 555+ see you "<<t3<<". Bye Bye \\(^ ^)/";
}