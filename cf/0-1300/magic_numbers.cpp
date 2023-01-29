#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char c;

    char prev = '0';
    while(cin >> c) {            
        if(c == '4') {
            if(prev != '1') {
                cout << "NO";
                return 0;
            }

            if(cin.eof()) break;

            cin >> c;
            
            if(c != '1' && c != '4') {
                cout << "NO";
                return 0;
            }

            prev = c;

        } else if(c != '1'){
            cout << "NO";
            return 0;
        } else {
            prev = c;
        }
    }

    cout << "YES";

    return 0;
}