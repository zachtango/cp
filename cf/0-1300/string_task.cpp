#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main() {
    
    string a;

    cin >> a;

    string s;

    
    for(auto c : a) {
        char l = tolower(c);
        if(l == 'a' ||
            l == 'o' ||
            l == 'y' ||
            l == 'e' ||
            l == 'u' ||
            l == 'i'
        ) {
            continue;
        }
        s.push_back('.');
        s.push_back(l);
    }

    cout << s;

    return 0;
}