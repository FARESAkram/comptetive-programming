#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long LL;

#define MOD 1000000007

LL qpower(LL x, LL n, LL mod){
    // Base case: exponent is 0, return 1
    if (n == 0)
        return 1;

    // Recursive case: exponent is even
    LL half = qpower(x, n / 2, mod);
    if (n % 2 == 0){
        return (half * half) % mod;
    }
    // Recursive case: exponent is odd
    return ((x % mod) * (half * half) % mod) % mod;
}

LL solve(LL x){
    // formula is 8 * 9^(x-1)
    return (8 * qpower(9, x - 1, MOD)) % MOD;
}

int main(){
    int test_cases;
    LL x;
    cin >> test_cases;
    while(test_cases--){
        cin >> x;
        cout << solve(x) << endl;
    }
    return 0;
}