# Nine - Kattis Problem Solution

This solution is for the **"Nine"** problem from Kattis. The problem requires calculating the result of a formula based on powers of 9, and efficiently computing the result modulo `10^9 + 7` for large exponents.

## Problem Summary

Given a number `x`, the task is to compute the result of the following expression:

> (8 * 9^(x-1)) % (10^9 + 7)


Where:
- `x` is a positive integer.
- `9^(x-1)` is the power of 9 raised to the exponent `x-1`.
- The result should be computed modulo `10^9 + 7`.

You are given multiple test cases, and for each test case, you must compute and output the result of the above expression.

## Approach

### Formula:
We are given that the expression is of the form:

> result = (8 * 9^(x-1)) % 1000000007


Where `1000000007` is the modulus value (`MOD`).

### Efficient Calculation Using Modular Exponentiation:
For large values of `x`, directly calculating `9^(x-1)` could result in very large numbers, so we use **modular exponentiation** to efficiently compute the result of `9^(x-1) % MOD`.

- **Modular exponentiation** allows us to compute powers efficiently under a modulus, using the method of exponentiation by squaring. This method breaks down the power calculation into smaller, manageable steps.
- The base case for exponentiation is when the exponent is 0, in which case any number raised to 0 equals 1.
- If the exponent is even, we recursively square the result of the half-exponent.
- If the exponent is odd, we multiply the result by the base value.

### Steps:
1. **Read the number of test cases.**
2. **For each test case**, compute `9^(x-1) % MOD` using the `qpower` function.
3. **Multiply the result** by 8, then take the result modulo `MOD` to get the final answer.

### Code Breakdown:

1. **qpower function**: Computes the result of `x^n % mod` using the method of exponentiation by squaring.
2. **solve function**: Calculates `8 * 9^(x-1) % MOD` for each test case.
3. **Main Function**: Reads input values and prints the results for each test case.

### Time Complexity:
- The time complexity for each test case is `O(log x)` due to the recursive nature of the `qpower` function.
- The overall time complexity for all test cases is `O(n * log x)`, where `n` is the number of test cases.
- Since we perform modular exponentiation, even large values of `x` can be handled efficiently.

### Space Complexity:
- The space complexity is `O(1)` as we only use a few variables to store intermediate results.

## Code Implementation

```cpp
#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long LL;

#define MOD 1000000007

LL qpower(LL x, LL n, LL mod){
    // Base case: exponent is 0, return 1
    if (n == 0)
        return 1;

    // Recursive case: exponent is even
    LL half = qpower(x, n / 2, mod);
    if (n % 2 == 0){
        return (half * half) % mod;
    }
    // Recursive case: exponent is odd
    return ((x % mod) * (half * half) % mod) % mod;
}

LL solve(LL x){
    // formula is 8 * 9^(x-1)
    return (8 * qpower(9, x - 1, MOD)) % MOD;
}

int main(){
    int test_cases;
    LL x;
    cin >> test_cases;
    while(test_cases--){
        cin >> x;
        cout << solve(x) << endl;
    }
    return 0;
}
```