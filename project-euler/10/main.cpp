#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ULL;

vector<ULL> sieve(ULL maxValue){
    vector<bool> isPrime(maxValue + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (ULL i = 2; i <= maxValue; i++){
        if (isPrime[i]){
            for (ULL j = i + i; j <= maxValue; j += i){
                isPrime[j] = false;
            }
        }
    }
    vector<ULL> primes;
    for (ULL i = 2; i <= maxValue; i++){
        if (isPrime[i]){
            primes.push_back(i);
        }
    }
    return primes;
}

ULL sumOfVector(vector<ULL> vec){
    ULL sum = 0;
    for (ULL i = 0; i < vec.size(); i++){
        sum += vec[i];
    }
    return sum;
}

int main(){
    int maxValue = 2000000;
    cout <<  "Sum of all primes below " << maxValue << " is: " << sumOfVector(sieve(maxValue)) << endl;
    return 0;
}