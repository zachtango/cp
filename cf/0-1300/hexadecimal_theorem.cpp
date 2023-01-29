#include <iostream>

using namespace std;

int main() {

    long long a = 0, b = 1;

    long long n;

    cin >> n;

    if(n == 0) {
        cout << "0 0 0";
        return 0;
    } else if(n == 1) {
        cout << "0 0 1";
        return 0;
    }

    while(true) {
        long long temp = a;
        a = b;
        b += temp;

        if(b == n) {
            cout << "0 " << temp << ' ' << a;
            break;
        }
    }

    return 0;
}