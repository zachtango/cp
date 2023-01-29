#include <iostream>

using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    /*
        start at a1
            calculate pos now to house a1
                add that to time
                update pos now to hosue a1
        continue to a2
            calculate pos now to house a2

        repeat until am

        if pos > num
            n - pos + num
    */

    long long t = 0;
    int pos = 1;
    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;
        // cout << t << ' ';
        if(pos > num)
            t += (n - pos + num);        
        else
            t += num - pos;
        pos = num;
    }

    cout << t;

    return 0;
}