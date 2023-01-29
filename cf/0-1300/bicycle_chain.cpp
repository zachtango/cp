#include <iostream>

using namespace std;

int main() {
    int n, m;

    int max_ratio = 0;
    int counter = 0;

    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> m;

    for(int j = 0; j < m; j++) {
        int b;
        cin >> b;
        for(int i = 0; i < n; i++) {
            if(b % a[i] == 0) {
                int d = b / a[i];
                if(d > max_ratio) {
                    max_ratio = d;
                    counter = 1;
                } else if(d == max_ratio) {
                    counter += 1;
                }
            }
        }
    }

    cout << counter;

    return 0;
}