#include <iostream>
#include <string>

using namespace std;

const string OFF = "OFF";
const string ON = "ON";

int main(){
    int t;

    cin >> t;

    for(int i = 1; i <= t; i++){
        int n, k;
        cin >> n >> k;

        bool is_on = true;

        for(int j = 0; j < n; j++){
            if((k & 1) == 0) {
                is_on = false;
                break;
            }
            k /= 2;
        }

        printf("Case #%d: %s\n", i, is_on != 0 ? ON.c_str() : OFF.c_str());
    }

}