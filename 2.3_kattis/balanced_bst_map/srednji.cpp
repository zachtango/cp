#include <iostream>
#include <map>

using namespace std;

#define MAX_N 100001

int sequence[MAX_N];
map<int, int> offset;
long long num_ss;
int n, b;

int main() {

    cin >> n >> b;

    int b_index;
    for(int i = 0; i < n; i++) {
        cin >> sequence[i];
        if(sequence[i] == b) {
            b_index = i;
        }
    }

    int o = 0;
    offset[0] = 1;
    // left
    for(int i = b_index - 1; i >= 0; i--) {
        if(sequence[i] > b) o += 1;
        else o -= 1;
        offset[o] += 1;
    }

    num_ss = offset[0];
    o = 0;
    // right
    for(int i = b_index + 1; i < n; i++) {
        if(sequence[i] > b) o += 1;
        else o -= 1;

        num_ss += offset[-o]; 
    }

    cout << num_ss;

    return 0;
}