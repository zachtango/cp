#include <iostream>

using namespace std;

#define D_MAX 100000

bool dragon[D_MAX + 1];

int main() {
    int k, l, m, n, d;

    cin >> k >> l >> m >> n >> d;

    int a, b, c, e;

    a = b = c = e = 0;

    while(
        a <= d || b <= d || c <= d || e <= d
    ) {
        if(a <= d) dragon[a] = true;
        if(b <= d) dragon[b] = true;
        if(c <= d) dragon[c] = true;
        if(e <= d) dragon[e] = true;

        a += k;
        b += l;
        c += m;
        e += n;
    }

    int counter = 0;
    for(int i = 1; i <= d; i++) {
        if(dragon[i]) counter += 1;
    }

    cout << counter;

    return 0;
}