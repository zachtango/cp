#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int start;

    while(!cin.eof()) {
        cin >> start;

        int num;
        while(cin >> num) {
            if(num % start == 0) {
                cout << num << endl;
                break;
            }
        }
    }

    return 0;
}