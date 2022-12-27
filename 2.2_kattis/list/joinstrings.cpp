#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100000

list<string> S[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
        S1, S2, S3, ..., Sn
    
        have values list corresponding to S1, S2, S3, ..., Sn

        store linked list where value is a linked list of values Si..j
        Li points to Li + 1
    */

    int n;
    cin >> n;

    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        S[i].push_back(s);
    }

    int last_a = 0;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;

        a -= 1, b -= 1;

        S[a].splice(S[a].end(), S[b]);
        last_a = a;
    }

    for(auto s : S[last_a]){
        cout << s;
    }

    return 0;
}