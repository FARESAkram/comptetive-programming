# Project Euler Problem 1 Solution

## Problem Description

Project Euler Problem 1 states:

> If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6, and 9. The sum of these multiples is 23.
>
> Find the sum of all the multiples of 3 or 5 below 1000.

You can find the problem details [here](https://projecteuler.net/problem=1).

## Solution Overview

The solution involves iterating through all natural numbers below 1000 and checking if each number is a multiple of 3 or 5. If it is, we add it to a cumulative sum. This implementation has a time complexity of O(n), where n is the upper limit (1000 in this case).

## Implementation

### Code

```cpp
#include<iostream>

using namespace std;

int main(){
    int sum = 0, maxInt = 1000;
    for (int i = 1; i < maxInt; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}
