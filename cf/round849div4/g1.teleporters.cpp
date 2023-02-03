#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    /*
        start at point 0

        teleporters at 
        point 1 ... n

        can calculate cost from point 0
        to each teleporter

        = (i - 0) to move + teleporter cost

        sort these costs
        iterate through sorted costs
        until no more coins
    */

    int t;
    cin >> t;

    while(t--) {
        int n, c;

        cin >> n >> c;
        // cout << "n: " << n << " c: " << c << endl;
        vector<int> cost;

        for(int i = 1; i <= n; i++) {
            int t_cost;
            cin >> t_cost;
            cost.push_back(i + t_cost);
        }

        sort(cost.begin(), cost.end());

        int counter = 0;
        for(auto const &t_cost : cost) {
            if(c >= t_cost) {
                c -= t_cost;
                counter += 1;
            } else {
                break;
            }
        }
        cout << counter << endl;
    }

    return 0;
}