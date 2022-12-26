#include <iostream>
#include <stack>

using namespace std;

#define MAX_N 100000

int socks[MAX_N * 2];

int main(){
    int n;
    cin >> n;
    stack<int> a, b;

    for(int i = 0; i < (2 * n); i++) cin >> socks[i];

    for(int i = (2 * n - 1); i >= 0; i--) a.push(socks[i]);
    
    int counter = 0;
    while(!a.empty()){
        if(b.empty() || (a.top() != b.top())) {
            b.push(a.top());
        } else {
            b.pop();
        }

        a.pop();
        counter += 1;
    }

    if(!b.empty()) cout << "impossible";
    else cout << counter;

    return 0;
}