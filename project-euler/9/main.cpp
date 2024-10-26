#include <iostream>
#include <math.h>

using namespace std;

long calcPyth(long a , long b){
    long cSquared = a*a + b*b;
    long c = sqrt(cSquared);
    if ( c*c == cSquared){
        return c;
    }
    return -1;
}



int main() {
    long maxValue, target = 1000;
    cin >> maxValue;
    for (long a = 1 ; a <= maxValue ; a ++ ){
        for (long b = 1 ; b <= maxValue ; b ++ ){
            long c = calcPyth(a,b);
            if ( c != -1 && (a + b + c) == target){
                cout << a * b * c << endl;
                return 0;
            }
        }
    }
    cout << "Not found in the range of " << maxValue << endl;
    return 0;
}
