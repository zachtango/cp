#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    for(int r = 0; r <= n; r++) {
        for(int i = 0; i < ((n - r) * 2); i++) {
            cout << ' ';
        }
        cout << 0;

        if(r != 0) {
            // first half
            for(int i = 1; i < r; i++) {
                cout << ' ' << i;
            }

            // middle digit
            cout << ' ' << r;

            // second half
            for(int i = r - 1; i >= 0; i--) {
                cout << ' ' << i;
            }
        }

        cout << endl;
    }

    for(int r = n - 1; r >= 0; r--) {
        for(int i = 0; i < ((n - r) * 2); i++) {
            cout << ' ';
        }
        cout << 0;

        if(r != 0) {
            // first half
            for(int i = 1; i < r; i++) {
                cout << ' ' << i;
            }

            // middle digit
            cout << ' ' << r;

            // second half
            for(int i = r - 1; i >= 0; i--) {
                cout << ' ' << i;
            }
        }

        cout << endl;
    }

    return 0;
}
