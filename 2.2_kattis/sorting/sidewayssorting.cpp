#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctype.h>

using namespace std;

int main(){
    int r, c;

    while(cin >> r >> c, r || c){
        char words[r][c];

        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                cin >> words[i][j];

        vector<string> cols;

        for(int j = 0; j < c; j++){
            string s = "";
            for(int i = 0; i < r; i++) s += words[i][j];

            cols.push_back(s);
        }

        stable_sort(cols.begin(), cols.end(), [](const string a, const string b){
            int n = a.length();
            string s1(' ', n);
            string s2(' ', n);

            for(int i = 0; i < n; i++){
                s1[i] = tolower(a[i]);
                s2[i] = tolower(b[i]);
            }

            return s1 < s2; 
        });

        // cout << r << ' ' << c << endl;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cout << cols[j][i];
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}