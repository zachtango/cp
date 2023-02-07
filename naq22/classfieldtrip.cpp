#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {
    string a, b;
    cin >> a >> b;

    string c;

    for(auto ch : a) {
        c.push_back(ch);
    }

    for(auto ch : b) {
        c.push_back(ch);
    }

    sort(c.begin(), c.end());

    cout << c;

    return 0;
}