#include <iostream>
#include <math.h>
using namespace std;

int a[8];

int main() {
    /*
    1 2 4
    1 3 6
    */

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a[num] += 1;

        if(num == 5 || num == 7) {
            cout << -1;
            return 0;
        }
    }

    bool x = (a[1] > 0 && a[2] > 0 && a[4] > 0),
        y = (a[1] > 0 && a[2] > 0 && a[6] > 0),
        z = (a[1] > 0 && a[3] > 0 && a[6] > 0);
    int ans[3];

    if(x || y || z) {
        if(a[6] < a[3]) {
            cout << -1;
            return 0;
        }

        ans[2] = a[3];

        a[6] -= a[3];
        a[1] -= a[3];
        a[3] = 0;

        a[2] -= a[6];
        a[1] -= a[6];

        ans[1] = a[6];
        ans[0] = a[4];

        a[6] = 0;

        a[4] -= a[2];
        a[1] -= a[2];
        a[2] = 0;

        if(!(a[1] || a[2] || a[3] || a[6])) {
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < ans[i]; j++) {
                    if(i == 0) {
                        cout << "1 2 4\n";
                    }

                    if(i == 1) {
                        cout << "1 2 6\n";
                    }

                    if(i == 2) {
                        cout << "1 3 6\n";
                    }
                }
            }

        } else {
            cout << -1;
        }

    } else {
        cout << -1;
    }
    

    return 0;
}