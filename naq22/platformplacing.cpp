#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

int main() {
    int n, s, k;

    cin >> n >> s >> k;

    vpii platforms;

    for(int i = 0; i < n; i++) {
        int p;
        cin >> p;

        p *= 2;

        platforms.push_back({p - s, p + s});
    }

    sort(platforms.begin(), platforms.end());

    for(int i = 1; i < n; i++) {
        // cout << platforms[i - 1].first << ' ' << platforms[i - 1].second << endl;
        if(platforms[i - 1].second > platforms[i].first) {
            cout << -1;
            return 0;
        }
    }

    // solve
    /*
        iterate through platforms

        for a platform,
        it's bounded by prev platform and next platform
        biggest increase you can make is
            min(k - s, curr.first - prev.second, next.first - curr.second)
    */
    int sum = 0;
    pii prev = {0, -10000000000};
    for(int i = 0; i < platforms.size(); i++) {
        pii next = {10000000000, 0};
        if(i + 1 < platforms.size()) {
            next = platforms[i + 1]; 
        }

        pii &p = platforms[i];

        // cout << k - s << ' ' << p.first - prev.second << ' ' << next.first - p.second << endl;
        int inc = min(k - s, min(p.first - prev.second, next.first - p.second));
        
        // cout << p.first << ' ' << p.second << endl;
        p.first -= inc;
        p.second += inc;
        // cout << p.first << ' ' << p.second << endl;
        sum += (p.second - p.first);

        prev = platforms[i];
        // cout << "prev: " << prev.first << ' ' << prev.second << endl;
    }

    cout << (sum / 2);

    return 0;
}
