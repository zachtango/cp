#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    int n;

    cin >> t;

    while(t--) {
        string s;
        cin >> n;
        cin >> s;

        int l = 0, r = n - 1;

        while(
            l < r &&
            (
                (s[l] == '1' && s[r] == '0') ||
                (s[l] == '0' && s[r] == '1')
            )
        ) {
            l += 1;
            r -= 1;
            n -= 2;
        }

        cout << n << endl;
    }

    return 0;
}