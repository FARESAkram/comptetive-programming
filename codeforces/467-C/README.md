# Maximum Sum of Non-overlapping Subarrays

## Problem Description

You are given a sequence of `n` integers. The goal is to select `k` non-overlapping subarrays, each of length `m`, such that the sum of these `k` subarrays is maximized.

### Input

1. **n**: Total number of integers in the sequence (1 ≤ m × k ≤ n ≤ 5000).
2. **m**: Length of each subarray.
3. **k**: Number of non-overlapping subarrays to select.
4. **Sequence**: A list of `n` integers where each integer `pi` (0 ≤ pi ≤ 10^9).

Full description [here](https://codeforces.com/problemset/problem/467/C).

### Output

Print the maximum possible sum that can be obtained by selecting `k` non-overlapping subarrays of length `m`.

## Solution Approach

The problem is approached using dynamic programming (DP) to efficiently determine the maximum sum of `k` non-overlapping subarrays of length `m`. Here's a detailed explanation of the approach:

### 1. Prefix Sum Calculation

To facilitate quick computation of subarray sums, we first compute the prefix sum array. The prefix sum array `prefixSum` is built such that:

- `prefixSum[i]` is the sum of the first `i` elements of the array.

Using the prefix sum array, the sum of any subarray from index `l` to `r` can be computed as:
\[ Sum[l, r] = prefixSum[r] - prefixSum[l-1] \]

### 2. Dynamic Programming Table

We use a 2D DP table `dp` where:
- `dp[i][group]` represents the maximum sum obtainable by selecting `group` non-overlapping subarrays from the first `i` elements of the array.

The dimensions of the DP table are:
- **Rows**: `numberOfElements + 1` (to handle subarrays ending at each index).
- **Columns**: `groupsCount + 1` (to handle up to `k` subarrays).

### 3. State Transition

The DP table is updated based on the following transition logic:
- For each possible ending position of a subarray, update `dp[i][group]` by considering whether including a subarray ending at index `i` yields a higher sum compared to excluding it.

The transition formula is:
\[ dp[i][group] = \max(dp[i-1][group], dp[i-groupSize][group-1] + \text{currentSubarraySum}) \]

Where:
- `dp[i-1][group]` is the value if we do not include the subarray ending at `i`.
- `dp[i-groupSize][group-1] + \text{currentSubarraySum}` is the value if we include the subarray ending at `i`.

### 4. Final Computation

After filling the DP table, the maximum sum achievable with exactly `k` non-overlapping subarrays is found in `dp[numberOfElements][groupsCount]`.

### Complexity Analysis

- **Time Complexity**: O(n * k)
  - We process each element for each group, leading to a time complexity proportional to the product of `n` and `k`.
- **Space Complexity**: O(n * k)
  - We maintain a DP table of size `(numberOfElements + 1) x (groupsCount + 1)`.

This approach ensures efficient computation even for the upper limits of the problem constraints.

## How to Run

1. **Compile the Code:**
   Use a C++ compiler such as g++:
   ```sh
   g++ -o main main.cpp

2. **Run the Code:**
  ```sh
  ./main
  ```


## Code Preview
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numberOfElements, groupSize, groupsCount;
    cin >> numberOfElements >> groupSize >> groupsCount;

    vector<ull> elements(numberOfElements + 1), prefixSum(numberOfElements + 1, 0);
    
    for (int i = 1; i <= numberOfElements; ++i) {
        cin >> elements[i];
        prefixSum[i] = prefixSum[i-1] + elements[i];  
    }

    vector<vector<ull>> dp(numberOfElements + 1, vector<ull>(groupsCount + 1, 0));

    for (int group = 1; group <= groupsCount; group++) { 
        for (int i = groupSize; i <= numberOfElements; i++) { 
            dp[i][group] = max(dp[i-1][group], dp[i-groupSize][group-1] + (prefixSum[i] - prefixSum[i-groupSize]));
        }
    }

    cout << dp[numberOfElements][groupsCount] << endl;

    return 0;
}

```
