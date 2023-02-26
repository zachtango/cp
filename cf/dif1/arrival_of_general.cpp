#include <iostream>
#include <math.h>

using namespace std;

int height[100];

int main() {
    int max_i, min_i, n;

    cin >> n;

    max_i = min_i = 0;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> height[i];

        if(height[max_i] < height[i]) {
            max_i = i;
        }

        if(height[min_i] >= height[i]) {
            min_i = i;
        }
    }

    int t = max_i + (n - min_i - 1);

    if(max_i > min_i)
        t -= 1;

    cout << t;

    return 0;
}