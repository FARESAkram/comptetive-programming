#include<bits/stdc++.h>

using namespace std;

int main(){
    int test_cases, n;
    cin >> test_cases;
    while (test_cases--) {
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        bool flag = false;
        for (int i = 0; i < n - 1; i++) {
            if (v[i + 1].find(v[i]) == 0) {
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