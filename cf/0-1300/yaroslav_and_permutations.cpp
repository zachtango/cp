#include <iostream>
#include <math.h>

using namespace std;

int n_count[1001];

int main() {
    int n;
    cin >> n;

    int m = 0;
    while(n--) {
        int num;
        cin >> num;
        n_count[num] += 1;
        
        if(n_count[m] < n_count[num])
            m = num;
    }

    int counter = 0;
    for(int i = 1; i < 1001; i++) {
        if(i == m)
            continue;
        counter += n_count[i];
    }

    if(counter < n_count[m] - 1) {
        cout << "NO";
    } else {
        cout << "YES";
    }

    return 0;
}