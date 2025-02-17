# Platforme - Kattis Problem Solution

This solution is for the **"Platforme"** problem from Kattis. The problem requires calculating the total length of exposed platform edges that are not supported by other platforms below them.

## Problem Summary

Given `n` horizontal platforms, each described by three integers `(y, x1, x2)`, where:
- `y` is the vertical position of the platform.
- `x1` and `x2` define the left and right endpoints of the platform.

The goal is to determine the **total length of exposed platform edges**, meaning the parts that are **not supported by another platform** below.

## Approach

### Observations:
1. **Sorting by height (y)**:
   - Platforms with a higher `y` coordinate are positioned above those with a lower `y`.
   - Sorting the input based on `y` ensures that we can process platforms from bottom to top.

2. **Handling Exposed Edges**:
   - For each platform, check if the **left and right endpoints** (`x1` and `x2`) are supported by any platform below.
   - If `x1` is **not supported**, the left edge contributes to the total sum.
   - If `x2` is **not supported**, the right edge contributes to the total sum.

3. **Efficient Checking**:
   - Iterate through **previously processed platforms** (i.e., lower platforms).
   - If a lower platform **overlaps horizontally** with the current platform, it provides support.
   - Stop checking once both edges are supported.

4. **Time Complexity**:
   - Sorting the platforms takes **O(n log n)**.
   - Checking for supports in the worst case takes **O(n²)**, but typically much faster in practice.
   - Overall, the time complexity is **O(n log n + n²)**, which simplifies to **O(n²)** for large inputs.
   - since n is <= 100, then O(n²) is acceptable.

### Steps:
1. **Read input and store platforms in a vector** as `(y, x1, x2)`.
2. **Sort the platforms in ascending order of `y`**.
3. **For each platform, determine the exposed length** by checking support from lower platforms.
4. **Sum up the exposed edges** for all platforms and print the result.

---

## Code Implementation

```cpp
#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> tiii;

long solve(vector<tiii> &v, int index)
{
    int y = get<0>(v[index]);
    int x1 = get<1>(v[index]);
    int x2 = get<2>(v[index]);
    long sum = 0;
    bool left, right;
    left = right = false;

    for (int i = index - 1; i >= 0; i--) {
        int current_y = get<0>(v[i]);
        int current_x1 = get<1>(v[i]);
        int current_x2 = get<2>(v[i]);

        // Check if the left side is supported
        if (!left && current_x1 <= x1 && x1 < current_x2) {
            sum += (y - current_y);
            left = true;
        }
        // Check if the right side is supported
        if (!right && current_x1 < x2 && x2 <= current_x2) {
            sum += (y - current_y);
            right = true;
        }
    }

    // If no support for a side, add full height
    if (!left) sum += y;
    if (!right) sum += y;
    
    return sum;
}

int main()
{
    int n, y, x1, x2;
    long sum = 0;
    vector<tiii> v;
    
    cin >> n;
    while (n--) {
        cin >> y >> x1 >> x2;
        tiii t = make_tuple(y, x1, x2);

        // Insert in sorted order based on 'y'
        auto it = lower_bound(v.begin(), v.end(), t, [](tiii a, tiii b) {
            return get<0>(a) < get<0>(b);
        });
        v.insert(it, t);
    }

    for (int i = 0; i < v.size(); i++) {
        sum += solve(v, i);
    }

    cout << sum << endl;
    return 0;
}
