#include <iostream>

using namespace std;

int main() {

    int z = 0, f = 0;

    int n;
    cin >> n;

    while(n--) {
        int num;
        cin >> num;

        if(num == 5) {
            f += 1;
        } else if(num == 0) {
            z += 1;
        } else {
            throw "err";
        }
    }

    if(f >= 9 && z >= 1) {
        while(f >= 9) {
            f -= 9;

            for(int i = 0; i < 9; i++) cout << 5;
        }

        for(int i = 0; i < z; i++) cout << 0;
    } else if(z >= 1) {
        cout << 0;
    } else {
        cout << -1;
    }

    return 0;
}