# Project Euler Solutions

This repository contains my solutions to various Project Euler problems implemented in C++. Each solution is accompanied by an explanation of the approach used.

## Problem 8: Largest Product in a Series

### Problem Description

The task is to find the largest product of a specified number of consecutive digits in a given 1000-digit number. 

You can find the problem details [here](https://projecteuler.net/problem=8).

### Solution Overview

To solve this problem, we need to calculate the product of each sequence of a specified number of consecutive digits in the large number and keep track of the largest product encountered.

1. **Conversion and Calculation**:
   - First, we convert each character in the string to an integer. This is done by creating a helper function `char_to_int`.
   - Next, we use a function `calcCharProd` to compute the product of a substring of consecutive digits starting from a given position.
  
2. **Sliding Window Approach**:
   - We use a loop to slide through each possible starting point for the consecutive sequence of digits and calculate the product.
   - We then compare each product to our current maximum and update it if the current product is larger.

### Implementation

Here’s the code implementation:

```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

// Converts a character to its integer value
int char_to_int(char x) {
    return x - '0';
}

// Computes the product of `size` consecutive digits starting at index `l` in `str`
LL calcCharProd(string str, int l, int size) {
    int maxSize = str.length();
    if (l < 0 || l + size > maxSize) {
        return 0;
    }
    LL prod = 1;
    for (int i = l; i < l + size; i++) {
        prod *= char_to_int(str[i]);
    }
    return prod;
}

int main() {
    // 1000-digit number as a string
    string input = 
        "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

    LL maxProduct = 0;
    int size;
    cin >> size;
    for(int i = 0; i < input.length() - size; i++) {
        maxProduct = max(maxProduct, calcCharProd(input, i, size));
    }
    cout << maxProduct << endl;
    return 0;
}
```