#include <iostream>
#include <iomanip>

using namespace std;

typedef unsigned long long ull;
typedef long double ld;

// Function to compute base^exponent using recursive fast exponentiation
ld quickPower(ld base, ull exponent){
    if ( exponent == 0 ){
        return 1;
    }
    // Compute base^(exponent / 2)
    ld halfPower = quickPower(base, exponent >> 1);
    if ( (exponent & 1) == 0 ){
        // If exponent is even, return halfPower^2
        return halfPower * halfPower;
    }
    // If exponent is odd, return base * halfPower^2
    return base * halfPower * halfPower;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ull n, t;
    cin >> n >> t;

    cout.precision(50);// Set precision to ensure relative error is within the limit

    cout << n * quickPower(1.000000011, t) << endl;
    
    return 0;
}
