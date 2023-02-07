#include <iostream>
#include <unordered_map>
#include <string>
#include <math.h>
using namespace std;

void print_map(const unordered_map<char, int> &m) {
    for(auto p : m) {
        cout << p.first << ": " << p.second << endl;
    }
}

int main() {
    int t;

    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        unordered_map<char, int> l_char_count,
                                 r_char_count;
        string s;
        cin >> s;

        l_char_count[s[0]] += 1;
        for(int i = 1; i < s.size(); i++) {
            r_char_count[s[i]] += 1;
        }

        int m = l_char_count.size() + r_char_count.size();
        // print_map(l_char_count);
        // cout << endl;
        // print_map(r_char_count);

        for(int i = 1; i < s.size(); i++) {
            l_char_count[s[i]] += 1;
            r_char_count[s[i]] -= 1;

            // print_map(l_char_count);
            // cout << endl;
            // print_map(r_char_count);

            if(r_char_count[s[i]] == 0) {
                r_char_count.erase(s[i]);
            }
            m = max(m, (int) (l_char_count.size() + r_char_count.size()));
        }

        cout << m << endl;
    }

    return 0;
}