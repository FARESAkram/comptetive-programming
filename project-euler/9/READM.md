# Project Euler Solutions

This repository contains my solutions to various Project Euler problems implemented in C++. Each solution is accompanied by an explanation of the approach used.

## Problem 9: Special Pythagorean Triplet

### Problem Description

The problem asks for a Pythagorean triplet, \( a, b, c \), such that:

1. \( a^2 + b^2 = c^2 \) (Pythagorean theorem),
2. \( a + b + c = 1000 \).

The task is to find this triplet and return the product \( a \times b \times c \).

More information on the problem can be found [here](https://projecteuler.net/problem=9).

### Solution Overview

To solve this problem, we need to find three numbers \( a \), \( b \), and \( c \) that satisfy both the Pythagorean theorem and the sum constraint. Given that \( a < b < c \), the code efficiently searches for values that meet both conditions using nested loops. The solution involves:

1. **Generating Pythagorean Triples**:
   - We generate values of \( a \) and \( b \) up to a given maximum and compute \( c \) using the Pythagorean relationship \( c = \sqrt{a^2 + b^2} \).
   - If \( c \) is an integer and \( a + b + c = 1000 \), then we have our answer.

2. **Early Exit**:
   - Since there is only one unique triplet for this problem, we immediately return the product once we find the correct values.

### Code Implementation

Here’s the code solution:

```cpp
#include <iostream>
#include <math.h>

using namespace std;

// Function to calculate `c` for a given `a` and `b` if it's a Pythagorean triplet
long calcPyth(long a , long b) {
    long cSquared = a * a + b * b;
    long c = sqrt(cSquared);
    if (c * c == cSquared) {
        return c;
    }
    return -1;
}

int main() {
    long maxValue, target = 1000;
    cin >> maxValue;
    for (long a = 1; a <= maxValue; a++) {
        for (long b = 1; b <= maxValue; b++) {
            long c = calcPyth(a, b);
            if (c != -1 && (a + b + c) == target) {
                cout << a * b * c << endl;
                return 0;
            }
        }
    }
    cout << "Not found in the range of " << maxValue << endl;
    return 0;
}
```