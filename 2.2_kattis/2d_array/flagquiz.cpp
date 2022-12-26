#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

#define MAX_N 100

string ans[MAX_N][MAX_N];
int changes[MAX_N];

int main(){
    string s;

    int n, m;

    getline(cin, s);
    cin >> n;
    getchar();

    string intermediate;

    for(int i = 0; i < n; i++){
        getline(cin, s);
        stringstream ss(s);

        int j = 0;
        while(getline(ss, s, ',')){
            ans[i][j] = s;
            j += 1;
        }
        m = j;
    }

    int min_changes = INT32_MAX;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;

            int count = 0;
            for(int k = 0; k < m; k++)
                if(ans[i][k] != ans[j][k]) count += 1;
            
            changes[i] = max(changes[i], count);
        }
        min_changes = min(min_changes, changes[i]);
    }

    for(int i = 0; i < n; i++){
        if(changes[i] == min_changes){
            for(int j = 0; j < m - 1; j++)
                cout << ans[i][j] << ',';

            cout << ans[i][m - 1] << endl;
        }
    }

    return 0;
}