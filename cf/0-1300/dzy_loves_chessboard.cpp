#include <iostream>

using namespace std;

bool is_black(int i, int j) {
    return (i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1);
}

int main() {
    int n, m;
    cin >> n >> m;

    char c;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> c;

            if(c == '.') {
                cout << (is_black(i, j) ? 'B' : 'W');
            } else {
                cout << '-';
            }
        }
        cout << endl;
    }

    return 0;
}