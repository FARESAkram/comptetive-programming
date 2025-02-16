# HToo - Kattis Problem Solution

This solution is for the "HToo" problem from Kattis, where the task is to determine how many molecules of a target compound can be synthesized from a given compound and a factor.

## Problem Summary

Given two chemical formulas as input:
- `input_formula`: The available molecule.
- `output_formula`: The desired molecule.
- `factor`: The number of times the `input_formula` is scaled by a given factor.

We need to determine how many times we can form the `output_formula` from the `input_formula` (taking into account the factor).

The chemical formulas are made up of atoms represented by capital letters (e.g., H for Hydrogen, O for Oxygen) and integer values indicating how many atoms of a particular type are present.

## Approach

1. **Molecule Parsing**:
   - We parse the chemical formulas into a dictionary (unordered map) where the key is the atom (represented by a character, e.g., 'H' for hydrogen) and the value is the number of atoms of that type.
   - We handle numbers directly following each atom to represent the count of that atom.
   - The atom counts in `input_formula` are scaled by the provided `factor`.

2. **Calculating Maximum Molecules**:
   - After parsing the formulas into atom counts, we compare the atom counts of the `output_formula` with those of the `input_formula`.
   - For each atom in the `output_formula`, we calculate how many complete `output_formula` molecules can be formed from the `input_formula`. This is done by taking the minimum of the ratio of available atoms in the `input_formula` to required atoms in the `output_formula`.

3. **Output**:
   - The result is the maximum number of `output_formula` molecules that can be synthesized. If any atom required by the `output_formula` is missing in the `input_formula`, the result is `0`.

## Code Explanation

The code is written in C++ and follows the steps outlined above.

### Key Functions

1. `is_a_number(char x)`:
   - Checks if a character is a number (i.e., between '0' and '9').

2. `convert_molecule_to_atoms(string s, int factor = 1)`:
   - Converts a chemical formula string into an unordered map of atoms and their counts. The `factor` parameter is used to scale the counts in the `input_formula`.

3. **Main Function**:
   - The main function reads the input strings, calls `convert_molecule_to_atoms` to parse the formulas, and computes how many molecules of the `output_formula` can be formed using the `input_formula`.

### Steps:

1. Read the `input_formula`, `factor`, and `output_formula`.
2. Parse both formulas into atom count maps.
3. Compare the atom counts in `input_formula` and `output_formula`, taking the factor into account.
4. Output the maximum number of molecules that can be synthesized.

## Time and Space Complexity

- **Time Complexity**:  
  - Parsing each formula takes linear time relative to the length of the formula (`O(n)`), where `n` is the length of the formula.
  - We iterate over the atoms in the `output_formula` and check their counts in `input_formula`, which also takes linear time.  
  Thus, the total time complexity is `O(n)` where `n` is the length of the longest formula.

- **Space Complexity**:  
  - We store the atom counts for both `input_formula` and `output_formula` in unordered maps, which requires space proportional to the number of unique atoms in the formulas. The space complexity is `O(m)` where `m` is the number of distinct atoms in both formulas.
