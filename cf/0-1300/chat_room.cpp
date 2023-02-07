#include <iostream>

using namespace std;

int main() {

    int chars[256];

    char c;

    char hello[] {"hello"};
    int i = 0;

    while(cin >> c) {
        if(c == hello[i]) {
            i += 1;
        }

        if(i == 5) break;
    }

    cout << (i == 5 ? "YES" : "NO");


    return 0;
}