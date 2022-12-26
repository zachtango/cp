#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack<int> s;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;

        if(!s.empty() && (s.top() + num) % 2 == 0) {
            s.pop();
            continue;
        }

        s.push(num);
    }

    cout << s.size();

    return 0;
}