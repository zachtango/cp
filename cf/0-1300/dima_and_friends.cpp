#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    int s = 0;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        s += num;
    }
    n += 1;
    int counter = 0;
    for(int i = 1; i <= 5; i++) {
        if( (s + i) % n != 1 ) {
            // cout << ( (s + i) % n ) << endl;
            counter += 1;
        }
    }

    cout << counter;
    
    return 0;
}