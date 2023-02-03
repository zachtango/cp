#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;

    cin >> s;

    int i = 0;
    for(const auto &c : s) {
        if(c == '0' || i == s.size() - 1) {
            break;
        }
        i += 1;
    }

    for(int j = 0; j < s.size(); j++) {
        if(i == j) {
            continue;
        }
        cout << s[j];
    }

    return 0;
}