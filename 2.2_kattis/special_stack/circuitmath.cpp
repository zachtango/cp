#include <iostream>
#include <stack>

using namespace std;

const int ASCII_OFFSET = 65;
const char TRUE = 'T';
const char FALSE = 'F';
const char OR = '+';
const char AND = '*';
const char NOT = '-';

bool char_values[26];

int main(){

    int n;
    cin >> n;

    char c;
    for(int i = 0; i < n; i++) {
        cin >> c;
        if(c == TRUE) char_values[i] = true;
        else if(c == FALSE) char_values[i] = false;
        else throw "Unknown input value";
    }

    stack<bool> S;
    while(cin >> c){
        switch(c){
            case AND:
            case OR: {
                bool a = S.top();
                S.pop();
                bool b = S.top();
                S.pop();

                bool res = a && b;

                if(c == OR) res = a || b;
                S.push(res);
                
                break;
            } case NOT: {
                bool a = S.top();
                S.pop();

                S.push(!a);
                break;
            } default:
                S.push(char_values[c - ASCII_OFFSET]);
                // cout << (int) (c - ASCII_OFFSET) << endl;
        }
    }

    cout << (S.top() ? 'T' : 'F');

    return 0;
}