#include <iostream>

using namespace std;

int main() {

    char c;

    while(cin >> c) {
        // cout << "c: " << c << endl;
        if(c == '.') {
            cout << 0;
        } else if(c == '-') {
            char next_c;
            cin >> next_c;

            if(next_c == '.') {
                cout << 1;
            } else if(next_c == '-') {
                cout << 2;
            }
        }
    }

    return 0;
}