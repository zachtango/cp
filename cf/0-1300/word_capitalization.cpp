#include <iostream>
#include <ctype.h>
using namespace std;

int main() {

    char c;
    cin >> c;

    cout << (char) toupper(c);

    while(cin >> c) 
        cout << c;

    return 0;
}