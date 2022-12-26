#include <iostream>
#include <string>

using namespace std;

#define NUM_BITS 32

int bits[NUM_BITS];

void instr(string in){
    int i, j;
    if(in == "SET") {
        cin >> i;
        bits[i] = 1;
    } else if(in == "CLEAR") {
        cin >> i;
        bits[i] = 0;
    } else if(in == "AND") {
        cin >> i >> j;
        if(bits[i] == 0 || bits[j] == 0) bits[i] = 0;
        else if(bits[i] == -1 || bits[j] == -1) bits[i] = -1;
        else bits[i] = 1;
    } else if(in == "OR") {
        cin >> i >> j;
        if(bits[i] == 1 || bits[j] == 1) bits[i] = 1;
        else if(bits[i] == -1 || bits[j] == -1) bits[i] = -1;
        else bits[i] = 0;
    } else throw "Unknown instr";
}

int main(){
    int n;

    while(cin >> n, n){
        for(int i = 0; i < NUM_BITS; i++) bits[i] = -1;

        string in;

        for(int i = 0; i < n; i++){
            cin >> in;
            instr(in);
        }

        for(int i = NUM_BITS - 1; i >= 0; i--)
            switch(bits[i]){
                case -1:
                    cout << '?';
                    break;
                case 0:
                    cout << '0';
                    break;
                case 1:
                    cout << '1';
                    break;
                default:
                    throw "Unknown bit value";
            }
        cout << endl;
    }
}