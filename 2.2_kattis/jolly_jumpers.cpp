#include <iostream>
#include <math.h>

using namespace std;

int main(){
    
    int n;

    while(cin >> n){
        bool diffs[n + 1];
        int S[n];

        for(int i = 0; i < n; i++){
            diffs[i] = false;
            cin >> S[i];
        }
        diffs[n] = false;

        for(int i = 1; i < n; i++){
            diffs[abs(S[i] - S[i - 1])] = true;
        }

        bool jolly = true;
        for(int i = 1; i < n; i++){
            if(!diffs[i]){
                jolly = false;
                break;
            }
        }

        if(jolly){
            cout << "Jolly\n";
        } else{
            cout << "Not Jolly\n";
        }
    }

    return 0;
}