#include <iostream>

using namespace std;

int main() {
    
    char chars[] {
        'c', 'o', 'd', 'e', 'f', 'r', 's'
    };

    int t;
    cin >> t;

    while(t--) {
        char c;
        cin >> c;

        for(int i = 0; i < 7; i++) {
            if(chars[i] == c) {
                cout << "YES\n";
                break;
            }

            if(i == 6) {
                cout << "NO\n";
            }
        }
    }



    return 0;
}