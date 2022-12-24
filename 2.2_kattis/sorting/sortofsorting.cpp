#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n;

    while(cin >> n, n){
        vector<string> names;
        string name;

        for(int i = 0; i < n; i++){
            cin >> name;
            names.push_back(name);
        }

        stable_sort(names.begin(), names.end(), [](const string a, const string b){
            return a.substr(0, 2) < b.substr(0, 2);
        });

        for(auto name : names) cout << name << endl;
        cout << endl;
    }

    return 0;
}