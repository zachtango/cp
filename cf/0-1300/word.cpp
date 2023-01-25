#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    int upper = 0;
    for(auto c : s) {
        if(isupper(c)) {
            upper += 1;
        }
    }

    if(upper > (s.size() - upper)) {
        for(auto c : s)
            cout << (char) toupper(c);
    } else {
        for(auto c : s)
            cout << (char) tolower(c);
    }

    return 0;
}