#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <algorithm>

using namespace std;

#define MIDDLE "middle"

typedef vector<string> vs;
typedef vector<pair<string, vs>> vpsvs;
typedef pair<string, vs> psvs;

void solve(vpsvs &people){
    stable_sort(people.begin(), people.end(), [](const psvs a, const psvs b){
        const string a_name = a.first,
                    b_name = b.first;
        const vs a_classlist = a.second,
                b_classlist = b.second;
        const int a_size = a_classlist.size(),
                b_size = b_classlist.size();
        
        int l = min(a_size, b_size);

        for(int i = 0; i < l; i++){
            if(a_classlist[i] == b_classlist[i]) continue;
            // cout << i << ' ' << l << ' ' << a_classlist[i] << ' ' << b_classlist[i] << endl;
            return a_classlist[i] > b_classlist[i];
        }

        if(a_size == b_size) return a_name < b_name;

        vs classlist;
        int size;
        if(a_size > b_size){
            classlist = a_classlist;
            size = a_size;
        } else{
            classlist = b_classlist;
            size = b_size;
        }
        
        int i = l;
        while(i < size && classlist[i] == MIDDLE) i += 1;
        if(i != size) {
            if(a_size > b_size) return classlist[i] > MIDDLE;
            else return classlist[i] < MIDDLE;
        }
        
        return a_name < b_name;
    });
}

int main(){
    int t, n;
    cin >> t;
    string EQUAL_SIGNS = "==============================";

    for(int i = 0; i < t; i++){
        vpsvs people;

        cin >> n;

        for(int i = 0; i < n; i++){
            string name, classes;
            cin >> name;
            name = name.substr(0, name.length() - 1);
            vs classlist;

            cin >> classes;
            stringstream ss(classes);
            string token;
            while(getline(ss, token, '-')) classlist.push_back(token);
            reverse(classlist.begin(), classlist.end());

            people.push_back({name, classlist});

            cin >> classes;
        }

        solve(people);

        for(auto p : people){
            cout << p.first << endl;
        }
        cout << EQUAL_SIGNS << endl;
    }

    return 0;
}