#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int m;
    cin >> m;

    string s;
    cin >> s;

    sort(s.begin(), s.begin() + s.size() / 2);
    sort(s.begin() + s.size() / 2, s.end());

    if(s[0] == s[m]) {
        cout << "NO";
        return 0;
    }

    bool less = s[0] < s[m];
    for(int i = 0; i < m; i++) {
        if(less) {
            if(s[i] >= s[i + m]) {
                cout << "NO";
                return 0;
            }
        } else if(s[i] <= s[i + m]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}