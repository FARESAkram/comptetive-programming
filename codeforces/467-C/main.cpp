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
