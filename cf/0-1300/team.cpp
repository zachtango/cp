#include <iostream>

using namespace std;

int main() {

    int n;

    cin >> n;

    int counter = 0;
    while(n--) {
        int a, b, c;
        cin >> a >> b >> c;

        if( a + b + c >= 2 ) {
            counter += 1;
        }
    }

    cout << counter;

    return 0;
}