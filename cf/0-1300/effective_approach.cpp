#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    int pos[n + 1];

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;

        pos[num] = i;
    }

    int m;
    cin >> m;
    long long left = 0, right = 0;
    while(m--) {
        int num;
        cin >> num;

        left += pos[num] + 1;
        right += n - pos[num];
    }

    cout << left << ' ' << right;

    return 0;
}