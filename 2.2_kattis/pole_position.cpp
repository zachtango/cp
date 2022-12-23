#include <iostream>

using namespace std;

int main(){
    /*
        input 2 <= N <= 10^3
        each of next N lines:
            integers C and P, separated by one space
            car number and number of positions car has one/lost
            1 <= C <= 10^4
            -10^6 <= P <= 10^6

        number of first car displayed at top, number of second car displayed next, so on
        
        during the race, number that's winning has its number displayed at top of pole, followed
        by second place, and so on

    */

    int n;
    while(cin >> n, n){
        int start[n];

        for(int i = 0; i < n; i++){
            start[i] = 0;
        }

        bool ok = true;
        int c, p;
        for(int i = 0; i < n; i++){
            cin >> c >> p;

            int start_p = i + p;
            cout << "start_p: " << start_p << endl;
            if(start_p < 0 || start_p >= n || start[start_p] != 0){
                ok = false;
            }

            start[start_p] = c;
        }

        if(ok){
            for(int i = 0; i < n; i++){
                cout << start[i] << ' ';
            }
        } else{
            cout << -1;
        }

        cout << endl;
    }


    return 0;
}
