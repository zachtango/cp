#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    int min_p, max_p;
    
    cin >> min_p;

    max_p = min_p;    

    int counter = 0;

    for(int i = 1; i < n; i++) {
        int num;
        cin >> num;

        if(num > max_p) {
            max_p = num;
            counter += 1;
        } else if(num < min_p) {
            min_p = num;
            counter += 1;
        }
    }

    cout << counter;

    return 0;
}