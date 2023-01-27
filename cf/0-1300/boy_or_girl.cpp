#include <iostream>

using namespace std;

int chars[256];

int main() {

    char c;
    while(cin >> c) {
        chars[c] += 1;
    }

    int distinct = 0;
    for(char i = 'a'; i <= 'z'; i++) {
        if(chars[i] >= 1)
            distinct += 1;
    }

    if(distinct % 2 == 0) {
        cout << "CHAT WITH HER!";
    } else {
        cout << "IGNORE HIM!";
    }

    return 0;
}