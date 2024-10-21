# Project Euler Solutions

This repository contains my solutions to various Project Euler problems implemented in C++. Each solution is accompanied by a brief overview and explanation of the approach taken.

## Problem 6: Sum Square Difference

### Problem Description

The sum of the squares of the first ten natural numbers is:

\[
1^2 + 2^2 + ... + 10^2 = 385
\]

The square of the sum of the first ten natural numbers is:

\[
(1 + 2 + ... + 10)^2 = 552^2 = 3025
\]

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is:

\[
3025 - 385 = 2640
\]

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

You can find the problem details [here](https://projecteuler.net/problem=6).

### Solution Overview

To solve this problem, I calculated both the sum of the squares of the first 100 natural numbers and the square of their sum. The final result is the difference between these two values.

1. **Sum of Squares**: This is calculated by iterating through all numbers from 1 to 100 and adding the square of each number to a cumulative total.
2. **Square of the Sum**: This is calculated by first obtaining the sum of all numbers from 1 to 100 and then squaring that sum.

### Implementation

### Code

```cpp
#include <iostream>

using namespace std;

int main()
{
    int maxValue = 100, sumSquares = 0, sum = 0;
    for (int i = 1; i <= maxValue; i++)
    {
        sumSquares += i * i; // Calculate sum of squares
        sum += i;            // Calculate sum of numbers
    }
    cout << sum * sum - sumSquares << endl; // Calculate the difference
    return 0;
}
