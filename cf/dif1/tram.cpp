#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;

    cin >> n;

    int cap = 0;
    int max_cap = 0;

    while(n--) {
        int a, b;
        cin >> a >> b;

        cap += b - a;

        max_cap = max(max_cap, cap);
    }

    cout << max_cap;

    return 0;
}