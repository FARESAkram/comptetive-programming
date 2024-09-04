# Ciel and Flowers - Codeforces Problem 322B

## Problem Description
You are given three integers `r`, `g`, and `b` representing the number of red, green, and blue flowers, respectively. You can make bouquets in two ways:
- A bouquet of 3 flowers of the same color.
- A bouquet of 1 flower from each color (1 red, 1 green, and 1 blue).

Your task is to maximize the number of bouquets you can form using the given flowers.

[Problem Link](https://codeforces.com/problemset/problem/322/B)

## Input
The input consists of three integers `r`, `g`, and `b` where:
- `r` (1 ≤ r ≤ 100),
- `g` (1 ≤ g ≤ 100),
- `b` (1 ≤ b ≤ 100).

## Output
Output a single integer, the maximum number of bouquets that can be formed.

## Approach

### Why Do We Perform Reductions?

The challenge is to form as many bouquets as possible, either using 3 flowers of the same color or using 1 flower from each color (1 red, 1 green, 1 blue). The tricky part is that the number of flowers in each color may not be perfectly divisible by 3, and we need to make the most of the leftovers.

To handle this, we use **reductions** by trying to remove 0, 1, or 2 flowers from each pile (red, green, and blue). Here’s why:

1. **Making 1 of each color bouquets**: If we have some leftover flowers after trying to group them in sets of 3, it might be better to use 1 flower from each color to form a bouquet instead of leaving flowers ungrouped. Reducing the number of flowers ensures we can efficiently handle small differences between `r`, `g`, and `b`.
   
2. **Ensuring Maximum Bouquets**: By trying out different reductions (removing 0, 1, or 2 flowers from each pile), we explore all possibilities for how the flowers might group together. This allows us to catch cases where we can optimize bouquet formation by adjusting the number of flowers in each pile.

### Strategy:
1. For each reduction (removing 0, 1, or 2 flowers from each pile), calculate how many "1 red, 1 green, and 1 blue" bouquets can be formed.
2. Then, check how many "3 of the same color" bouquets can be made from the remaining flowers.
3. Keep track of the maximum number of bouquets formed after each reduction.

### Solution:
- **Step 1**: Try reducing the number of flowers in each pile by 0, 1, or 2.
- **Step 2**: For each reduced number of flowers:
  - First, form as many "1 red, 1 green, and 1 blue" bouquets as possible.
  - Then, group the remaining flowers into as many "3 flowers of the same color" bouquets as possible.
- **Step 3**: Track and return the maximum number of bouquets that can be formed.


## Code

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int r, g, b;
    cin >> r >> g >> b;

    int max_bouquets = 0;

    for (int reduction = 0; reduction < 3; reduction++) {
        int rr = r - reduction;
        int gg = g - reduction;
        int bb = b - reduction;

        if (rr >= 0 && gg >= 0 && bb >= 0) {
            max_bouquets = max(max_bouquets, reduction + rr/3 + gg/3 + bb/3);
        }
    }

    cout << max_bouquets << endl;

    return 0;
}

```
