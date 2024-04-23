#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}


void importDataFromFile(string fname, vector<string>& name, vector<int>& score, vector<char>& grade){

    string line;
    ifstream myfile(fname);

    char format[] = "%[^:]:%d %d %d";
    
    char nname[100];
    int a,b,c; 
    int z;

    while(getline(myfile,line))
    {

    const char * lline = line.c_str();

    sscanf(lline,format,nname,&a,&b,&c);

    z = a+b+c;
    
    name.push_back(nname);
    score.push_back(z);
    grade.push_back(score2grade(z));
    

    }
}

void getCommand(string &command,string &key){
    
    cout << "Please input your command: ";
    cin >> command;
    if(toUpperStr(command) == "GRADE" || toUpperStr(command) == "NAME" ){    
        cin.ignore();
        getline(cin,key);
    }
}  


void searchName(vector<string> name, vector<int> score, vector<char> grade, string key){
    
    int count = 0;
    
    cout << "---------------------------------\n";
    
    for(unsigned int i=0; i<name.size(); i++){
        if(key == toUpperStr(name[i])){
            cout << name[i] << "'s score = " << score[i] << endl;
            cout << name[i] << "'s grade = " << grade[i] << endl;
            count++;
        }else if(i == name.size()-1 && count==0){
            cout << "Cannot found." << endl;
        }
    }

    cout << "---------------------------------\n";
}

void searchGrade(vector<string> &name, vector<int> &score, vector<char> &grade, string key){

    int count = 0;
    char x = key[0];
    
    cout << "---------------------------------\n";
    
    for(unsigned int i=0; i<name.size(); i++){
        if(x == grade[i]){
            cout << name[i] << " " << "(" << score[i] <<")" << endl;
            count++;
        }else if(i == name.size()-1 && count==0){
            cout << "Cannot found." << endl;
        }
    }

    cout << "---------------------------------\n";
}




int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}