#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>

using namespace std;

void solve(vector<string> &words){
    sort(words.begin(), words.end(), [](const string a, const string b){
        string a_copy(a);
        string b_copy(b);

        reverse(a_copy.begin(), a_copy.end());
        reverse(b_copy.begin(), b_copy.end());

        return a_copy < b_copy;
    });
}

int main(){
    ofstream out;
    // out.open("out.txt");

    while(!cin.eof()){
        string s;
        vector<string> words;
        int m = 0;

        while(getline(cin, s), s.size()) {
            m = max(m, (int) s.length());
            words.push_back(s);
        }

        solve(words);

        for(auto w : words){
            cout << setw(m) << right << w << endl;
        }
        if(!cin.eof()) cout << endl;
    }

    // out.close();

    return 0;
}