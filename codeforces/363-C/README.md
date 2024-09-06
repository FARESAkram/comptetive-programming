# Typo Correction in Words

## Problem Overview

This program addresses a common problem in text editing: correcting specific types of typos. In particular, two types of typos are considered:

1. **Three Consecutive Identical Letters**: For example, in the word `helllo`, the three `l`s form a typo.
2. **Pairs of Consecutive Identical Letters**: Two identical letters immediately followed by another two identical letters. For example, in `helloo` and `aabbcc`, the pairs `oo` and `bb` form typos.

The goal is to delete the minimum number of letters from the word so that no typos remain in the final word.

## Solution Outline

### Approach
1. **Iterate Over the Input Word**: We go through each character in the input word.
2. **Check for Consecutive Triples**: If a character forms a group of three consecutive identical characters, skip it.
3. **Check for Double Pairs**: If a character forms two consecutive pairs of identical characters (e.g., `aabb`), skip the second pair.
4. **Build the Final Word**: Only add characters that do not form the above typos to the final output word.

## Code Overview

### Key Sections:
- **Input Parsing**: Read the input word as a string.
- **First Pass to Eliminate Triple Consecutive Characters**: This part of the code ensures that no three consecutive identical characters exist in the word.
- **Second Pass to Eliminate Double Pairs**: This ensures that no consecutive pairs of identical characters exist.
  
### Example Input
> helloo

### Example Output
> hello

In this case, one of the `o`s is removed to eliminate the typo.

## Code 

```cpp
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input word from the user
    string originalWord, tempWord = "", finalWord = "";
    cin >> originalWord;
    
    int originalLength = originalWord.length();
    
    // If the word is very short (less than or equal to 2 characters), it can't have typos
    if (originalLength <= 2) {
        cout << originalWord << endl;
        return 0;
    }

    // First two characters are always valid (cannot form a typo with just two characters)
    tempWord += originalWord.at(0);
    tempWord += originalWord.at(1);

    // Loop through the word starting from the third character
    for (int i = 2; i < originalLength; i++) {
        char currentChar = originalWord.at(i);
        int tempLength = tempWord.length();

        // Check if the last two characters are identical and match the current character
        if (currentChar == tempWord.at(tempLength - 1) && currentChar == tempWord.at(tempLength - 2)) {
            continue; // Skip to avoid three consecutive identical characters
        }
        // Add the current character if it's not part of a typo
        tempWord += currentChar;
    }

    int tempLength = tempWord.length();

    // If after the first pass the string is still short, output it directly
    if (tempLength <= 3) {
        cout << tempWord << endl;
        return 0;
    }

    // Add the first three characters to the final result
    finalWord = tempWord.substr(0, 3);

    // Check for the second type of typo (aabb pattern)
    for (int i = 3; i < tempLength; i++) {
        char currentChar = tempWord.at(i);
        int finalLength = finalWord.length();

        // If the last two characters are identical and the previous two are also identical, skip this character
        if (currentChar == finalWord[finalLength - 1] && finalWord[finalLength - 2] == finalWord[finalLength - 3]) {
            continue; // Skip to avoid 'aabb' pattern
        }
        // Add the current character to the final result
        finalWord += tempWord.at(i);
    }

    // Output the final corrected word
    cout << finalWord << endl;

    return 0;
}
```

### Time Complexity:
The solution works in **O(n)**, where `n` is the length of the input word. This ensures that the algorithm can handle the maximum input size efficiently.

## Conclusion
The program efficiently removes typos by ensuring that no three consecutive identical letters or two consecutive pairs of identical letters remain in the final word. The solution guarantees that the minimum number of letters is deleted to meet these conditions.
