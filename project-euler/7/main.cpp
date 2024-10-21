#include <iostream>

using namespace std;

typedef unsigned long long ll;

bool isPrime(ll n){
    if(n <= 1) return false;
    for( ll i = 2; i * i <= n; i++ ){
        if(n % i == 0) return false;
    }
    return true;
}

int main()
{
    int index = 10001;
    ll currentPrime = 2;
    while(true){
        if(isPrime(currentPrime)){
            index--;
        }
        if ( index == 0 ) break;
        currentPrime++;
    }
    cout << currentPrime << endl;
    return 0;
}