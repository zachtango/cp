#include <iostream>
#include <string>
#include <stack>

using namespace std;

const string UNDO = "undo";

int mod(int a, int b){
    int c = a % b;
    return (c < 0) ? c + b : c;
}

int main(){
    
    stack<int> S;

    int n, k;
    cin >> n >> k;

    string instr;

    while(cin >> instr){
        if(instr == UNDO) {
            int m;
            cin >> m;
            
            for(int i = 0; i < m; i++) S.pop();
        }
        else S.push(stoi(instr));
    }

    int sum = 0;
    
    while(!S.empty()){
        sum += S.top();
        S.pop();
    }

    cout << mod(sum, n);
    
    return 0;
}