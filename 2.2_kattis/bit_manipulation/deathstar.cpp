#include <iostream>

using namespace std;

#define N_MAX 1000

int a[N_MAX];

int main(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int num;
            cin >> num;

            a[i] |= num;
        }
    }

    for(int i = 0; i < n; i++) cout << a[i] << ' ';

    return 0;
}