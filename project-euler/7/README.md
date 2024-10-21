# Project Euler Solutions

This repository contains my solutions to various Project Euler problems implemented in C++. Each solution is accompanied by a brief overview and explanation of the approach taken.

## Problem 7: 10,001st Prime

### Problem Description

The task is to find the 10,001st prime number.

You can find the problem details [here](https://projecteuler.net/problem=7).

### Solution Overview

To solve this problem, I implemented a simple algorithm to find prime numbers by checking each number sequentially until I reach the 10,001st prime.

1. **Prime Checking**: I defined a function `isPrime` that checks if a number is prime by testing divisibility against all integers up to its square root.
  
2. **Counting Primes**: In the main function, I initialized a counter for the prime index and a variable to track the current number being checked. The loop continues until the counter reaches 10,001.

### Implementation

### Code

```cpp
#include <iostream>

using namespace std;

typedef unsigned long long ll;

bool isPrime(ll n){
    if(n <= 1) return false; // Numbers less than 2 are not prime
    for(ll i = 2; i * i <= n; i++){ // Check divisibility up to the square root of n
        if(n % i == 0) return false; // n is divisible by i, so it's not prime
    }
    return true; // n is prime
}

int main()
{
    int index = 10001; // We want to find the 10,001st prime
    ll currentPrime = 2; // Start checking from the first prime number
    while(true){
        if(isPrime(currentPrime)){
            index--; // Found a prime, decrement the index
        }
        if (index == 0) break; // If we found the 10,001st prime, exit the loop
        currentPrime++; // Check the next number
    }
    cout << currentPrime << endl; // Output the 10,001st prime number
    return 0;
}
