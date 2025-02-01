# Luhn Checksum Solution

This program implements the solution to the Luhn checksum problem, which is commonly used for validating various identification numbers such as credit card numbers.

## Problem Description

The Luhn algorithm (also known as the Luhn formula or modulus 10 algorithm) is a simple checksum formula used to validate a variety of identification numbers. The goal is to determine if a given string (representing a number) passes the Luhn checksum validation.

For a number to be valid:
1. Starting from the right, double every second digit.
2. If doubling a digit results in a number greater than 9, subtract 9 from the result.
3. Sum all the digits, including the doubled ones.
4. If the total sum is divisible by 10, the number is valid.

## Approach

1. **Transform Function**: 
   - The function `transform(char x)` handles doubling every second digit from the right. If the result of doubling the digit is less than 10, the number is returned as-is. Otherwise, the digits are summed together to ensure the result is a single digit (i.e., the sum of digits of the doubled number).
   
2. **Main Logic**: 
   - The `solve` function iterates through the digits of the number string, starting from the rightmost digit.
   - It adds the digits at odd positions directly and applies the transformation to the digits at even positions.
   - The final checksum is validated by checking if the sum of all digits modulo 10 is 0.

3. **Input/Output**:
   - The program first reads the number of test cases.
   - For each test case, it reads a number as a string, performs the Luhn validation, and prints either "PASS" (if the number is valid) or "FAIL" (if the number is invalid).

## Time Complexity

The time complexity of this solution is **O(n)**, where `n` is the length of the string representing the number.

- In the worst case, we loop through all the digits of the number once (O(n)).
- For each digit, we perform constant time operations (e.g., subtraction, addition, and transformation).
  
Thus, the time complexity for each test case is linear with respect to the number of digits in the number.

## Space Complexity

The space complexity is **O(1)** because we only store a few variables (`sum`, `j`, etc.) and don't use any additional data structures that grow with the input size. The space needed does not depend on the input size, making it constant space.