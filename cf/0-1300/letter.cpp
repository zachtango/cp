#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;
    
int a_char_count[256];
int b_char_count[256];

int main() {

    string a, b;

    getline(cin, a);
    getline(cin, b);

    for(auto const &c : a) {
        a_char_count[c] += 1;
    }

    for(auto const &c : b) {
        b_char_count[c] += 1;
    }

    for(char i = 'a'; i <= 'z'; i++) {
        if(a_char_count[i] < b_char_count[i] ||
            a_char_count[toupper(i)] < b_char_count[toupper(i)]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}