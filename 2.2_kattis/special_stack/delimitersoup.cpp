#include <iostream>
#include <string>
#include <stack>
using namespace std;

const char OPEN_PAR = '(',
            OPEN_BRACK = '[',
            OPEN_BRACE = '{',
            CLOSE_PAR = ')',
            CLOSE_BRACK = ']',
            CLOSE_BRACE = '}';

bool is_open(char c){
    return c == OPEN_PAR || c == OPEN_BRACK || c == OPEN_BRACE;
}

bool is_match(char open, char close){
    return (
        (open == OPEN_PAR && close == CLOSE_PAR) ||
        (open == OPEN_BRACE && close == CLOSE_BRACE) ||
        (open == OPEN_BRACK && close == CLOSE_BRACK)
    );
}

int main(){

    int n;
    cin >> n;
    getchar();

    string L;
    getline(cin, L);

    stack<char> S;
    for(int i = 0; i < L.size(); i++){
        if(L[i] == ' ') continue;

        if(is_open(L[i])) S.push(L[i]);
        else if(S.empty() || !is_match(S.top(), L[i])) {
            cout << L[i] << ' ' << i;
            return 0;
        } else S.pop();
    }

    cout << "ok so far";
    return 0;
}