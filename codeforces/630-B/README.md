# Moore's Law Transistor Growth Calculator

This program calculates the estimated number of transistors in a dense integrated circuit after a given number of seconds, starting from an initial number of transistors. The growth follows an exponential increase as per Moore's Law.

## Problem Statement

Given:
- `n`: The initial number of transistors.
- `t`: The number of seconds that have passed since the initial measurement.

The number of transistors increases by a factor of `1.000000011` every second. The goal is to compute the estimated number of transistors after `t` seconds with a relative error not exceeding `10^-6`.

## Approach

### Exponential Growth Calculation

The problem can be modeled as exponential growth where:
- The growth factor per second is `1.000000011`.
- The growth follows the formula: 
> final_count = n * (1.000000011)^t


To compute this efficiently given the potentially large value of `t`, we use **fast exponentiation** (also known as **exponentiation by squaring**).

### Fast Exponentiation

The `quickPower` function computes `base^exponent` using recursion. This method reduces the time complexity to `O(log(exponent))`, which is efficient even for large values of `t`.

### Implementation

Here's a brief overview of the implemented solution:

1. **Function `quickPower`**:
 - Recursively calculates the power of a number.
 - If the exponent is `0`, it returns `1`.
 - For even exponents, it computes `(halfPower)^2`.
 - For odd exponents, it computes `base * (halfPower)^2`.

2. **Main Function**:
 - Reads input values for `n` and `t`.
 - Uses `quickPower` to calculate `(1.000000011)^t`.
 - Multiplies the result by `n` to get the final count.
 - Outputs the result with a precision of `15` decimal places to ensure accuracy.

### Code

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

// Function to compute base^exponent using recursive fast exponentiation
long double quickPower(long double base, unsigned long long exponent) {
  if (exponent == 0) {
      return 1;
  }
  // Compute base^(exponent / 2)
  long double halfPower = quickPower(base, exponent >> 1);
  if ((exponent & 1) == 0) {
      // If exponent is even, return halfPower^2
      return halfPower * halfPower;
  }
  // If exponent is odd, return base * halfPower^2
  return base * halfPower * halfPower;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  unsigned long long n, t;
  cin >> n >> t;

  cout.precision(15);  // Set precision to ensure relative error is within the limit
  cout << fixed;       // Ensure output is in fixed-point notation
  cout << n * quickPower(1.000000011, t) << endl;

  return 0;
}
```