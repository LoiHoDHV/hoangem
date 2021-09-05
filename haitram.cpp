#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int *p[5];
    for(int i = 0; i < 5; i++){
        p[i] = new int[5];
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            p[i][j] = i + 1;
        }
        cout << endl;
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << p[i][j] << " ";
        }
        cout << endl;
    }

}