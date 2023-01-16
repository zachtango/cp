#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

map<int, multiset<int, greater<int>>, greater<int>> quests;

void process(const string &s) {

    if(s == "add") {
        int e, g;
        cin >> e >> g;

        quests[e].insert(g);
    } else if(s == "query") {
        int x;
        cin >> x;

        auto it = quests.lower_bound(x);
        // cout << "d: " << distance(quests.begin(), it) << endl;
        long long g = 0;
        while(it != quests.end()) {
            // for(auto q : quests) cout << q.e << ' ';
            // cout << endl;
            x -= it->first;
            g += *(it->second.begin());
            // cout << "s: " << s.e << endl;

            it->second.erase(it->second.begin());
            if(it->second.size() == 0) quests.erase(it);

            it = quests.lower_bound(x);

            // cout << "size: " << quests.size() << " d: " << distance(quests.begin(), it) << endl;
        }

        cout << g << endl;
    } else {
        throw "Unknown action";
    }
    // for(auto q : quests) cout << q.e << ' ';
    //     cout << endl;
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        process(s);
    }

    return 0;
}