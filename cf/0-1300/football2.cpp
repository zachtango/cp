#include <iostream>

using namespace std;

int main() {

    char c;

    cin >> c;

    char prev = c;

    int counter = 1;
    while(cin >> c) {
        if(c == prev) counter += 1;
        else {
            prev = c;
            counter = 1;
        }
        if(counter == 7) {
            cout << "YES";
            return 0;
        } 
    }

    cout << "NO";
    return 0;
}