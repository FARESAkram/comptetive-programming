#include<iostream>

using namespace std;

int main(){

    int sum = 0, maxInt = 1000;
    for (int i = 1 ; i < maxInt ; i ++ ){
        if (i % 3 == 0 || i % 5 == 0){
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}