# Project Euler Problem 4 Solution

## Problem Description

Project Euler Problem 4 states:

> A palindromic number reads the same both ways. The largest palindrome made from the product of two 3-digit numbers is 906609, which is equal to 913 * 993.
>
> Find the largest palindrome made from the product of two 3-digit numbers.

You can find the problem details [here](https://projecteuler.net/problem=4).

## Solution Overview

This solution involves iterating through all products of two 3-digit numbers (from 100 to 999) and checking if each product is a palindrome. If it is, the algorithm keeps track of the largest palindrome found. The implementation uses a helper function to determine if a number is a palindrome.

## Implementation

### Code

```cpp
#include <iostream>

using namespace std;

bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    int largestPalindrome = -1;
    for (int i = 100; i <= 999; i++) {
        for (int j = 100; j <= 999; j++) {
            int num = i * j;
            string str = to_string(num);
            if (isPalindrome(str) && num > largestPalindrome) {
                largestPalindrome = num;
            }
        }
    }
    cout << largestPalindrome << endl;
    return 0;
}
