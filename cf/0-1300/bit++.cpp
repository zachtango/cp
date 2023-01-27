#include <iostream>

using namespace std;

int main() {
    int n;
    int x = 0;

    cin >> n;

    while(n--) {
        char c;
        for(int i = 0; i < 3; i++) {
            cin >> c;
            if(c == '-' || c == '+') {
                cin >> c;
                i += 1;
                if(c == '-')
                    x -= 1;
                else
                    x += 1;
            } 
        }
    }

    cout << x;

    return 0;
}