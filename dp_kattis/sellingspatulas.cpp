#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#define MINUTES 1440
// SOLUTION NOT FINISHED YET
void solve(int n) {
    
    vector<int> profit(MINUTES, -8);
    
    int start;
    int end;
    for(int i = 0; i < n; i++) {
        int m;
        float p;

        cin >> m >> p;

        if(i == 0)
            start = m;
        else if(i == n - 1)
            end = m;

        profit[m] += (int) (p * 100);
    }

    int path[MINUTES];
    int max_i = start;
    path[start] = start;
    for(int i = start + 1; i <= end; i++) {
        int with = profit[i] + profit[i - 1];

        if(with > profit[i]) {
            profit[i] = with;
            path[i] = i - 1;
        } else {
            path[i] = i;
        }

        if(profit[i] > profit[max_i])
            max_i = i;
    }

    if(profit[max_i] > 0) {
        cout << fixed << setprecision(2) << ( (float) profit[max_i] / 100 ) << ' ';

        int end = max_i;
        int i = max_i;

        while(i != path[i]) {
            i = path[i];
        }

        cout << i << ' ' << end << endl;
    } else {
        cout << "no profit\n";
    }
}

int main() {
    int n;
    
    while(cin >> n, n) {
        solve(n);
    }

    return 0;
}