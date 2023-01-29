#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef queue<int> qi;

struct Node {
    vi neighbors;
    vi conditions;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<int, Node> g;
    unordered_map<string, int> t_to_int;
    qi absolute;
    unordered_set<int> toppings;

    int id = 0;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if(s == "if") {
            vs conditions;
            bool AND = false;
            while(true) {
                string t, o;
                cin >> t >> o;

                if(t_to_int.count(t) == 0) {
                    t_to_int[t] = id;
                    id += 1;
                }

                conditions.push_back(t);
                if(o == "then") {
                    cin >> t;

                    if(t_to_int.count(t) == 0) {
                        t_to_int[t] = id;
                        id += 1;
                    }

                    for(auto const &condition : conditions) {
                        int c = t_to_int[condition];
                        g[c].neighbors.push_back(t_to_int[t]);

                        if(AND) {
                            g[t_to_int[t]].conditions.push_back(c);
                        }
                    }
                    break;
                }
                else if(o == "and") {
                    AND = true;

                }
            }
        } else {
            if(t_to_int.count(s) == 0) {
                t_to_int[s] = id;
                id += 1;
            }
            absolute.push(t_to_int[s]);
        }
    }

    // for(auto const &p : g) {
    //     cout << p.first << ": ";
    //     for(auto const &n : p.second) {
    //         cout << n << ' ';
    //     }
    //     cout << endl;
    // }

    while(absolute.size() > 0) {
        int t = absolute.front();

        bool ok = true;
        for(auto const &c : g[t].conditions) {
            if(toppings.count(c) == 0) {
                ok = false;
                break;
            }
        }
        absolute.pop();
        if(!ok) continue;

        toppings.insert(t);
        for(auto const &tn : g[t].neighbors) {
            if(toppings.count(tn) == 0) {
                absolute.push(tn);
            }
        }
    }

    // for(auto const &t : toppings) {
    //     cout << t << ' ';
    // }

    cout << toppings.size();

    return 0;
}
