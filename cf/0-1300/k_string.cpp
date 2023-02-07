#include <iostream>

using namespace std;

int chars[256];

int main() {

    int k;
    cin >> k;

    char c;

    while(cin >> c) {
        chars[c] += 1;
    }

    for(char i = 'a'; i <= 'z'; i++) {
        if(chars[i] % k != 0) {
            cout << -1;
            return 0;
        }
    }

    for(int j = 0; j < k; j++) {
        for(char i = 'a'; i <= 'z'; i++) {
            if(chars[i] > 0) {
                for(int m = 0; m < chars[i] / k; m++) {
                    cout << i;
                }
            }
        }
    }

    return 0;
}


