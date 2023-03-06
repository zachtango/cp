#include <iostream>


using namespace std;

int main() {
    int n, p;

    cin >> n >> p;

    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= p;
    }

    int m = a[0];
    for(int i = 1; i < n; i++) {
        a[i] = max(a[i - 1] + a[i], a[i]);
        m = max(m, a[i]);
    }

    cout << m << endl;
    
    return 0;
}