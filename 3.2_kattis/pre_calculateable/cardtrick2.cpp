#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int main() {
    /*
        i cards moved from top to bottom
        top card picked and it's ith of spades
    */

    int t;

    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        /*
            n cards in deck a
            for i in [1, n]
                i top cards moved to bottom of deck
                top card revealed to be i, move to deck b
        
            reverse

            n cards in deck b [1 ... n] n is at top

            for i in [1, n]
                move top card from deck b to deck a
                i bottom cards of deck a moved to top
        */

        vi a, b;

        for(int i = 1; i <= n; i++) {
            b.push_back(i);
        }

        for(int i = 1; i <= n; i++) {
            int top = b.back();
            b.pop_back();
            a.push_back(top);
            // cout << "n: " << (n - i + 1) << endl;

            // for(auto c : a) {
            //     cout << c << ' ';
            // }
            // cout << endl;

            for(int j = 0; j < (n - i + 1); j++) {
                rotate(a.begin(), a.begin() + 1, a.end());
                // for(auto c : a) {
                //     cout << c << ' ';
                // }
                // cout << endl;
            }

            
        }

        reverse(a.begin(), a.end());

        for(auto c : a) {
            cout << c << ' ';
        }
        cout << endl;
    }


    return 0;
}