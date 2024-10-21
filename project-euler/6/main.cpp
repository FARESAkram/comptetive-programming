#include <iostream>

using namespace std;

int main()
{
    int maxValue = 100, sumSquares = 0, sum = 0;
    for ( int i =  1; i <= maxValue; i++ ){
        sumSquares += i * i;
        sum += i;
    }
    cout << sum * sum - sumSquares << endl;
    return 0;
}