#include <iostream>

using namespace std;

int G[1000000];

int main(){
    /*
        keep track of gi - 1
        iterate through Array and find gi > gi - 1
        make gi gi - 1 and continue to iterate from where you are
    */

    int n;
    cin >> n;
    
    int i = 1;
    cin >> G[0];

    int a;
    for(int j = 0; j < n - 1; j++){
        cin >> a;
        if(a > G[i - 1]){
            G[i] = a;
            i++;
        }
    }

    cout << i << endl;
    for(int j = 0; j < i - 1; j++){
        cout << G[j] << ' ';
    }
    cout << G[i - 1] << endl;

    return 0;
}