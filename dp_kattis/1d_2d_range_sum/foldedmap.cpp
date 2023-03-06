#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    
    int Ar, Ac, Tr, Tc;
    while(cin >> Ar) {
        cin >> Ac >> Tr >> Tc;
        int dp[Ar][Ac];
        
        // cout << "\n    ";
        // for(int j = 0; j < Ac; j++) {
        //     cout << setw(4) << j + 1;
        // }
        // cout << endl;

        for(int i = 0; i < Ar; i++) {
            // cout << setw(4) << i + 1;
            for(int j = 0; j < Ac; j++) {

                dp[i][j] = 0;
                
                char c;
                cin >> c;
                // cout << setw(4) << c;

                if(c == 'X') dp[i][j] = 1;

                if(i > 0)
                    dp[i][j] += dp[i - 1][j];
                
                if(j > 0)
                    dp[i][j] += dp[i][j - 1];

                if(i > 0 && j > 0)
                    dp[i][j] -= dp[i - 1][j - 1];
            }
            // cout << endl;
        }

        int min_count = INT32_MAX;
        // try all starts
        for(int i = 0; i < Tr; i++) {
            for(int j = 0; j < Tc; j++) {        

                int r = i;

                int counter = 0;
                
                while(r < Ar - 1 + Tr) {
                    int c = j;
                    while(c < Ac - 1 + Tc) {
                        int x_count = dp[min(Ar - 1, r)][min(Ac - 1, c)];

                        if(r >= Tr)
                            x_count -= dp[r - Tr][min(Ac - 1, c)];
                        if(c >= Tc)
                            x_count -= dp[min(Ar - 1, r)][c - Tc];
                        if(r >= Tr && c >= Tc)
                            x_count += dp[r - Tr][c - Tc];
                        
                        if(x_count > 0) {
                            counter += 1;
                        }

                        c += Tc;
                    }
                    r += Tr;
                }
                min_count = min(min_count, counter);
            }
        }

        cout << min_count << endl;
    }

    return 0;
}