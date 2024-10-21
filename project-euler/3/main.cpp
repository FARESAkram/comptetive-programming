#include <iostream>

using namespace std;

typedef long long ll;

bool isPrime(ll n)
{
    if (n <= 1)
    {
        return false;
    }
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ll maxValue = 600851475143, maxPrimeFactor = 0, currentPrime = 2;
    while (maxValue > 1)
    {
        while (maxValue % currentPrime == 0)
        {
            maxPrimeFactor = currentPrime;
            maxValue /= currentPrime;
        }
        currentPrime ++;
        while(!isPrime(currentPrime)){
            currentPrime += 1;
        }
    }
    cout << maxPrimeFactor << endl;
    return 0;
}