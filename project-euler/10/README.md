# Project Euler Solutions

This repository contains my solutions to various Project Euler problems implemented in C++. Each solution is accompanied by an explanation of the approach used.

## Problem 10: Summation of Primes

### Problem Description

The problem requires calculating the sum of all prime numbers below a given number (in this case, 2 million). The solution should be efficient due to the large input size. More information on the problem can be found [here](https://projecteuler.net/problem=10).

### Solution Overview

To solve this problem efficiently, we use the **Sieve of Eratosthenes** algorithm to generate all prime numbers up to `maxValue` (2 million). The algorithm works by iteratively marking the multiples of each prime starting from 2, leaving only prime numbers marked as `true`. The algorithm is efficient and well-suited for generating all primes up to a large number.

Once we have a list of primes, we calculate their sum by iterating through the generated prime numbers.

### Code Implementation

Here’s the code solution:

```cpp
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ULL;

// Function to generate a list of primes up to `maxValue` using the Sieve of Eratosthenes
vector<ULL> sieve(ULL maxValue) {
    vector<bool> isPrime(maxValue + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (ULL i = 2; i <= maxValue; i++) {
        if (isPrime[i]) {
            for (ULL j = i + i; j <= maxValue; j += i) {
                isPrime[j] = false;
            }
        }
    }
    vector<ULL> primes;
    for (ULL i = 2; i <= maxValue; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

// Function to calculate the sum of a vector of primes
ULL sumOfVector(vector<ULL> vec) {
    ULL sum = 0;
    for (ULL i = 0; i < vec.size(); i++) {
        sum += vec[i];
    }
    return sum;
}

int main() {
    int maxValue = 2000000;
    cout << "Sum of all primes below " << maxValue << " is: " << sumOfVector(sieve(maxValue)) << endl;
    return 0;
}
```