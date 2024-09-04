#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int r, g, b;
    cin >> r >> g >> b;

    int max_bouquets = 0;

    for (int reduction = 0; reduction < 3; reduction++) {
        int rr = r - reduction;
        int gg = g - reduction;
        int bb = b - reduction;

        if (rr >= 0 && gg >= 0 && bb >= 0) {
            max_bouquets = max(max_bouquets, reduction + rr/3 + gg/3 + bb/3);
        }
    }

    cout << max_bouquets << endl;

    return 0;
}
