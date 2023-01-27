#include <iostream>


using namespace std;

int main() {
    int n;

    cin >> n;

    int pages[7];

    for(int i = 0; i < 7; i++) {
        cin >> pages[i];
    }

    int i = -1;
    do {
        i = (i + 1) % 7;
        n -= pages[i];
    } while(n > 0);

    cout << (i + 1);

    return 0;
}