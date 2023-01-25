#include <iostream>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    char queue[n];

    for(int i = 0; i < n; i++) {
        cin >> queue[i];
    }

    while(t--) {
        for(int i = 0; i < n - 1; i++) {
            if(queue[i] == 'B' && queue[i + 1] == 'G') {
                queue[i] = 'G';
                queue[i + 1] = 'B';
                i += 1;
            }
        }
    }

    for(int i = 0; i < n; i++)
        cout << queue[i];

    return 0;
}