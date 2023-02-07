#include <iostream>

using namespace std;

int main() {

    int m = 0;

    int n, k;
    cin >> n >> k;

    int f[n];
    for(int i = 0; i < n; i++) {
        cin >> f[i];
    }

    int min_sum = 0;
    for(int i = 0; i < k; i++) {
        min_sum += f[i];
    }

    int sum = min_sum;
    for(int i = 1; i < n - k + 1; i++) {
        sum -= f[i - 1];
        sum += f[i + k - 1];

        if(min_sum > sum) {
            min_sum = sum;
            m = i;
        }
    }

    cout << m + 1;

    return 0;
}