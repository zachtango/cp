#include <iostream>
#include <utility>

using namespace std;

pair<int, int> move(int x, int y, char m) {
    switch(m) {
        case 'U':
            return {x, y + 1};
        case 'D':
            return {x, y - 1};
        case 'L':
            return {x - 1, y};
        case 'R':
            return {x + 1, y};
    }
    return {-1, -1};
}

int main() {
    int t;
    int n;
    cin >> t;
    while(t--) {
        int x = 0, y = 0;

        cin >> n;
        // cout << "n: " << n << endl;
        bool passed = false;
        while(n--) {
            char m;
            cin >> m;
            // cout << "m: " << m << endl;
            
            auto p = move(x, y, m);
            
            x = p.first;
            y = p.second;

            if(x == 1 && y == 1) {
                passed = true;
            }
        }

        cout << (passed ? "YES" : "NO") << endl;
    }


    return 0;
}