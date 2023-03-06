#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

#define MINUTES 1440

void solve(int n) {   
    vector<int> profit(MINUTES, -8);
    
    int start;
    int end;
    // get input
    for(int i = 0; i < n; i++) {
        int m;
        float p;

        cin >> m >> p;

        if(i == 0)
            start = m;
        if(i == n - 1)
            end = m;

        profit[m] += (int) round(p * 100);
    }

    // calc MSS[i] = max(MSS[i - 1] + A[i], A[i])
    int path_start[MINUTES];
    int max_i = start;
    path_start[start] = start; // starting time in the interval

    for(int i = start + 1; i <= end; i++) {
        int with = profit[i] + profit[i - 1];

        if(with > profit[i]) {
            profit[i] = with;
            path_start[i] = path_start[i - 1];
        } else {
            path_start[i] = i;
        }

        if(profit[i] > profit[max_i] || 
            (profit[i] == profit[max_i] && (i - path_start[i] < max_i - path_start[max_i]))) // smaller interval
            max_i = i;
    }

    if(profit[max_i] > 0) {
        cout << fixed << setprecision(2) << ( (float) profit[max_i] / 100 ) << ' ' 
            << path_start[max_i] << ' ' << max_i << endl;
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