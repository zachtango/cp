#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int main() {
    
    vi hshoes;

    for(int i = 0; i < 4; i++) {
        int num;
        cin >> num;
        hshoes.push_back(num);
    }

    sort(hshoes.begin(), hshoes.end());

    int counter = 0;
    for(int i = 0; i < 3; i++) {
        if(hshoes[i] == hshoes[i + 1])
            counter += 1;
    }

    cout << counter;
    
    return 0;
}