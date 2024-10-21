# Project Euler Solutions

This repository contains my solutions to various Project Euler problems implemented in C++. Each solution is accompanied by a brief overview and explanation of the approach taken.

## Problem 5: Smallest Multiple

### Problem Description

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder. What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

You can find the problem details [here](https://projecteuler.net/problem/5).

### Solution Overview

To find the smallest positive number that is evenly divisible by all numbers from 1 to 20, I used the method of prime factorization. The goal is to identify the highest powers of each prime number that are needed to cover all the numbers from 1 to 20.

### Prime Factor Selection

**Identifying Prime Factors**: For each number from 20 down to 1, I determined its prime factorization. The key is to ensure that for each prime, we take the highest power needed among all the numbers.

   - **20**: \(2^2 \times 5\) (highest power of 2 is \(2^2\))
   - **19**: \(19\)
   - **18**: \(2 \times 3^2\) (we already have \(2\) from 20, so we take \(3^2\) from 9)
   - **17**: \(17\)
   - **16**: \(2^4\) (highest power of 2)
   - **15**: \(3 \times 5\) (both are covered)
   - **14**: \(2 \times 7\) (both are covered)
   - **13**: \(13\)
   - **12**: \(2^2 \times 3\) (we already have \(2^2\) and \(3\))
   - **11**: \(11\)
   - **10**: \(2 \times 5\) (both are covered)
   - **9**: \(3^2\) (highest power of 3)
   - **8**: \(2^3\) (highest power of 2)
   - **7**: \(7\)
   - **6**: \(2 \times 3\) (both are covered)
   - **5**: \(5\)
   - **4**: \(2^2\) (highest power of 2)
   - **3**: \(3\)
   - **2**: \(2\)
   - **1**: Not considered (does not affect the product)

### Implementation

### Code

```cpp
#include <iostream>

using namespace std;

int main()
{
    cout << 20 * 19 * 9 * 17 * 4 * 7 * 13 * 11;
    return 0;
}
