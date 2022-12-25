#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int hash(vi R, int x, int y){
    int v = 0;
    for(auto r : R) v = (v * x + r) % y;
}

int main(){
    int t, 
        n,
        a, b, c,
        x, y;

    cin >> t;
    
    for(int i = 0; i < t; i++){
        cin >> n >> a >> b >> c >> x >> y;
    }


    return 0;
}