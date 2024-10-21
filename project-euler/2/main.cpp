#include<iostream>

using namespace std;


int main(){

    long sum = 0;
    int maxValue = 4000000, a =  1, b = 2;
    sum = b;
    while (a <= maxValue || b <= maxValue) {
        long temp = a;
        a = b;
        b = temp + b;
        if (b <= maxValue &&  b % 2 == 0){
            sum += b;
        }
    }
    cout << sum << endl;
    return 0;
}