#include <iostream>

using namespace std;

int chars[256];

int main() {

    char c;
    while(cin >> c)
        chars[c] += 1;

    int odds = 0;
    for(char i = 'a'; i <= 'z'; i++) {
        if(chars[i] % 2 == 1) 
            odds += 1;
    }

    if(odds == 0 || odds == 1 || odds % 2 == 1) {
        cout << "First";
    } else {
        cout << "Second";
    }

    return 0;
}