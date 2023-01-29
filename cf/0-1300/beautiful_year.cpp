#include <iostream>
#include <string>

using namespace std;

bool chars[500];

int main() {
    int year;
    cin >> year;

    while(year++) {
        string s = to_string(year);
        
        for(char c = '0'; c <= '9'; c++)
            chars[c] = false;

        bool unique = true;
        for(auto c : s) {
            if(chars[c]) {
                unique = false;
                break;
            }
            chars[c] = true;
        }
        
        if(unique) {
            cout << year;
            return 0;
        }
    }

    return 0;
}