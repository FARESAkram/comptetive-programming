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
