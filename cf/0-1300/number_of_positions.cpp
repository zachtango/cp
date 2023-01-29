#include <iostream>
#include <math.h>

using namespace std;

int main() {
    
    int n, a, b;

    cin >> n >> a >> b;

    cout << (n - max(n - b - 1, a));

    return 0;
}