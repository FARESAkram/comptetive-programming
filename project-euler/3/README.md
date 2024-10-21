# Project Euler Problem 3 Solution

## Problem Description

Project Euler Problem 3 states:

> The prime factors of 13195 are 5, 7, 13, and 29.
>
> What is the largest prime factor of the number 600851475143?

You can find the problem details [here](https://projecteuler.net/problem=3).

## Solution Overview

This solution finds the largest prime factor of the number 600851475143 by iteratively dividing the number by its smallest prime factor. The algorithm checks for prime factors starting from 2, continuing until the number is reduced to 1. This implementation effectively utilizes a helper function to check for prime numbers, ensuring efficient factorization.

## Implementation

### Code

```cpp
#include <iostream>

using namespace std;

typedef long long ll;

bool isPrime(ll n)
{
    if (n <= 1)
    {
        return false;
    }
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ll maxValue = 600851475143, maxPrimeFactor = 0, currentPrime = 2;
    while (maxValue > 1)
    {
        while (maxValue % currentPrime == 0)
        {
            maxPrimeFactor = currentPrime;
            maxValue /= currentPrime;
        }
        currentPrime++;
        while (!isPrime(currentPrime))
        {
            currentPrime += 1;
        }
    }
    cout << maxPrimeFactor << endl;
    return 0;
}
