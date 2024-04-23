#include <iostream>
using namespace std;

int main(int avgc, char* argv[]){

    int N = avgc - 1;
    float sum = 0;

 if(avgc == 1){
    cout << "Please input numbers to find average." << endl;
 }else{
 
    for(int i = 0; i < avgc-1; i++){
        sum += atof(argv[i+1]);
    }
        cout << "---------------------------------" << endl;
        cout << "Average of " << N << " numbers = " << sum/N << endl;
        cout << "---------------------------------" << endl;
}

}
