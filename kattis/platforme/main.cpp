#include<bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> tiii;

long solve(vector<tiii> &v, int index)
{
    int y = get<0>(v[index]);
    int x1 = get<1>(v[index]);
    int x2 = get<2>(v[index]);
    long sum = 0;
    bool left , right;
    left = right = false;
    for (int i = index - 1 ; i >= 0 ; i--){
        int current_y = get<0>(v[i]);
        int current_x1 = get<1>(v[i]);
        int current_x2 = get<2>(v[i]);
        // for left side
        if (!left && current_x1 <= x1 && x1 < current_x2 ){
            sum += (y - current_y);
            left = true;
        }
        // for right side
        if (!right && current_x1 < x2 && x2 <= current_x2){
            sum += (y - current_y);
            right = true;
        }
    }
    if ( !left ) sum += y;
    if ( !right ) sum += y;
    return sum;
}

int main()
{
    int n, y , x1, x2;
    long sum = 0;
    vector<tiii> v;
    cin >> n;
    while ( n-- )
    {
        cin >> y >> x1 >> x2;
        // insert the tuple in the vector in ascending order of y
        // find the position where the tuple should be inserted
        tiii t = make_tuple(y, x1, x2);
        auto it = lower_bound(v.begin(), v.end(), t, [](tiii a, tiii b) {
            return get<0>(a) < get<0>(b);
        });
        v.insert(it, t);
    }
    for(int i = 0 ; i < v.size() ; i++){
        sum += solve(v, i);
    }
    cout << sum << endl;
    return 0;
}