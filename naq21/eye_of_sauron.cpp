#include <iostream>
#include <string>

using namespace std;

int main() {
    int left = 0, right = 0;

    string s;
    cin >> s;

    int l = 0;
    while(s[l] != '(') {
        l += 1;
        left += 1;
    }

    int r = s.size() - 1;
    while(s[r] != ')') {
        r -= 1;
        right += 1;
    }

    if(left != right) cout << "fix";
    else cout << "correct";

    return 0;
}