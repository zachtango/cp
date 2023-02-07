#include <iostream>
#include <string>

using namespace std;

bool chars[256];

int main() {
    string n;
    cin >> n;

    for(const auto &c : n) {
        chars[c] = true;
    }

    /*
        get all the digits you haven't used in a set

        let's say n is x digits long

        to produce the closest lower number below n:
            2 cases:
            1. no digits less than the left most digit
                then the closest will be x - 1 digits of the same largest digit in your set        

            2. digits less than left most digit
                then the closest will be x digits
                    leftmost digit is largest digit < left most digit of n
                    rest of x - 1 digits are largest digit in your set

        to produce closest higher number above n:
            2 cases:
            1. no digits greater than left most digit of n
                then the closest will be x + 1 digits of the same lowest digit in your set
            2. digits greater than left most digit
                then the closest will be x digits
                    the leftmost digit is lowest digit > left most digit of n
                    rest of x - 1 digits are lowest digit in your set
    */
    for(char i = '1'; i <= '9'; i++) {
        if(!chars[i]) {
            break;
        }
        if(i == '9') {
            cout << "Impossible";
            return 0;
        }
    }

    int x = n.size();
    string lower;
    // gen lower number
    for(char i = n[0] - 1; i > '0'; i--) {
        if(!chars[i]) {
            lower.push_back(i);
            break;
        } 
    }

    for(char i = '9'; i >= '0'; i--) {
        if(!chars[i]) {
            for(int j = 0; j < x - 1; j++) {
                lower.push_back(i);
            }
            break;
        }
    }


    // gen higher number
    string higher;
    bool h = false;
    for(char i = n[0] + 1; i <= '9'; i++) {
        if(!chars[i]) {
            higher.push_back(i);
            h = true;
            break;
        }
    }
    if(!h) {
        for(char i = '1'; i <= '9'; i++) {
            if(!chars[i]) {
                higher.push_back(i);
                break;
            }
        }
    } else {
        x -= 1;
    }
    for(char i = '0'; i <= '9'; i++) {
        if(!chars[i]) {
            for(int j = 0; j < x; j++) {
                higher.push_back(i);
            }
            break;
        }
    }
    // cout << "h: " << higher << endl;

    // cout << lower << ' ' << n << ' ' << higher << endl;

    if(lower.size() == 0) {
        cout << higher;
        return 0;
    }

    long long a = stoll(lower),
                b = stoll(n),
                c = stoll(higher);

    if(a == 0) {
        cout << c;
        return 0;
    }

    long long dif1 = b - a,
        dif2 = c - b;

    if(dif1 == dif2) {
        cout << a << ' ' << c;
    } else if(dif1 < dif2) {
        cout << a;
    } else {
        cout << c;
    }

    return 0;
}