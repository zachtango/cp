#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int len = 5;
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            int num;
            cin >> num;

            if(num == 1) {
                cout << abs(i - 2) + abs(j - 2);
                return 0;
            }
        }
    }

    return 0;
}