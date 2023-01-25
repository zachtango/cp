#include <iostream>
#include <string>
using namespace std;

int main() {
    char c;
    int num_lucky = 0;

    while(cin >> c) {
        if(c == '4' || c == '7') {
            num_lucky += 1;
        }
    }

    string s = to_string(num_lucky);

    for(auto c : s) {
        if(c != '4' && c != '7') {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}