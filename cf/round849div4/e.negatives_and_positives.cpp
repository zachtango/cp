#include <iostream>
#include <math.h>

using namespace std;

int main() {
    /*
        if you have odd number of negatives
            you have one negative left
            to apply to num

        if you have even num of negatives
            you can perform operations
            such that no negative nums left
        
        if there's a zero
            you can perform operations
            such that no negative nums left
    */

    int t;
    
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int a;
        int num_negatives = 0;
        long long sum = 0;
        int m = INT32_MAX;
        for(int i = 0; i < n; i++) {
            cin >> a;

            if(a < 0) {
                num_negatives += 1;
            }

            sum += abs(a);
            m = min(m, abs(a));
        }
        // cout << zero << ' ' << num_negatives << endl;
        if(num_negatives % 2 == 0) {
            cout << sum << endl;
        } else {
            cout << (sum - (2 * m)) << endl;
        }
    }

    return 0;
}