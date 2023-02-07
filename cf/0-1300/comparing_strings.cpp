#include <iostream>
#include <string>

using namespace std;

int main() {
    string first, second;

    cin >> first >> second;

    if(first.size() != second.size()) {
        cout << "NO";
        return 0;
    }

    int d = 0;
    int x, y;

    for(int i = 0; i < first.size(); i++) {
        if(first[i] != second[i]) {
            if(d == 0) {
                x = i;
            } else {
                y = i;
            }
            d += 1;
        }

        if(d > 2) {
            cout << "NO";
            return 0;
        }
    }

    if( (d == 2 && 
        first[x] != second[y] || 
        first[y] != second[x]) ||
        d == 1) {
        cout << "NO";
    } else {
        cout << "YES";
    }

    return 0;
}