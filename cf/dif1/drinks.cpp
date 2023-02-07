#include <iostream>

using namespace std;


int main() {
    int n;

    cin >> n;

    int fraction = 0;
    int total = n;

    while(n--) {
        int f;
        cin >> f;
        fraction += f;
    }

    cout << (double) fraction / total;

    return 0;
}