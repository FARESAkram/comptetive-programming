# Project Euler Problem 2 Solution

## Problem Description

Project Euler Problem 2 states:

> Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
>
> 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040.
>
> By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

You can find the problem details [here](https://projecteuler.net/problem=2).

## Solution Overview

This solution involves generating Fibonacci numbers and summing the even-valued terms that do not exceed four million. The algorithm uses a loop to calculate Fibonacci numbers iteratively, maintaining a cumulative sum of even-valued terms. This implementation has a time complexity of O(n), where n is the number of Fibonacci terms generated.

## Implementation

### Code

```cpp
#include<iostream>

using namespace std;

int main(){
    long sum = 0;
    int maxValue = 4000000, a = 1, b = 2;
    sum = b;
    while (a <= maxValue || b <= maxValue) {
        long temp = a;
        a = b;
        b = temp + b;
        if (b <= maxValue && b % 2 == 0) {
            sum += b;
        }
    }
    cout << sum << endl;
    return 0;
}
