#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

typedef vector<string> vs;

void solve(vector<vs> &songs, int attribute){
    stable_sort(songs.begin(), songs.end(), [attribute](const vs a, const vs b){
        return a[attribute] < b[attribute];
    });
}

int main(){
    vs attr;
    string line;

    getline(cin, line);
    
    stringstream ss(line);
    while(getline(ss, line, ' ')) attr.push_back(line);

    int m, n;
    
    cin >> m;
    getchar();
    vector<vs> songs(m);

    for(int i = 0; i < m; i++){
        getline(cin, line);
        stringstream ss(line);
        while(getline(ss, line, ' ')) songs[i].push_back(line);
    }
    
    cin >> n;
    string attribute;
    for(int i = 0; i < n; i++){
        cin >> attribute;
        auto it = find(attr.begin(), attr.end(), attribute);
        
        solve(songs, it - attr.begin());
        
        for(auto a : attr) cout << a << ' ';
        cout << endl;
        for(auto s : songs){
            for(auto a : s) cout << a << ' ';
            cout << endl;
        }
        if(i != n - 1) cout << endl;
    }

    return 0;
}