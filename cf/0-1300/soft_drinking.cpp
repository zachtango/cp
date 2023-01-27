#include <iostream>
#include <math.h>

using namespace std;

int main() {

    int n, k, l, c, d, p, nl, np;

    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int ml = k * l;
    int slices = c * d;

    int t = min(ml / nl / n, min(slices / n, p / np / n));

    cout << t;

    return 0;
}