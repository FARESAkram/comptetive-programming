# Phone List - Kattis Problem Solution

This solution is for the **"Phone List"** problem from Kattis. The problem requires determining whether a list of phone numbers is **consistent**, meaning no number is a **prefix** of another number in the list.

---

## Problem Summary

Given `n` phone numbers, the goal is to determine if the list is **consistent**. A list is considered **inconsistent** if at least one number is a prefix of another.

### **Example**
#### **Input**

2 
3 
911 
97625999 
91125426 
5 
113 
12340 
123440 
12345 
98346

#### **Output**

NO
YES


**Explanation:**
- In the first case, `"911"` is a prefix of `"91125426"`, so the list is **inconsistent**.
- In the second case, no number is a prefix of another, so the list is **consistent**.

---

## Approach

### Observations:
1. If a number is a **prefix** of another, it must appear **before** that number in **lexicographical order**.
2. **Sorting** the list ensures that **potential prefix relationships** are between consecutive elements.
3. After sorting, we can efficiently check **only adjacent elements** to determine if one is a prefix of another.

---

## Steps:
1. **Read the input and store the phone numbers in a vector.**
2. **Sort the list in lexicographical order.**
    The reason for sorting is that if a number is a prefix of another, it must appear before that number in lexicographical order.
    otherwise , it cannot be a prefix.
3. **Check adjacent pairs** in the sorted list:
   - If a number is a **prefix** of the next number, mark the list as **inconsistent**.
4. Print `"NO"` if the list is inconsistent; otherwise, print `"YES"`.

---

## Code Implementation

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int test_cases, n;
    cin >> test_cases;
    
    while (test_cases--) {
        cin >> n;
        vector<string> v(n);
        
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        // Sort numbers lexicographically
        sort(v.begin(), v.end());

        bool flag = false;

        // Check adjacent elements for prefix property
        for (int i = 0; i < n - 1; i++) {
            if (v[i + 1].find(v[i]) == 0) { // Check if v[i] is a prefix of v[i + 1]
                flag = true;
                break;
            }
        }

        if (flag) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    
    return 0;
}
```