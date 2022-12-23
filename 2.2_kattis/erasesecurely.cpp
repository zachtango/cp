#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    string a, b;

    cin >> n >> a >> b;

    if(n % 2 == 0){
        if(a == b){
            cout << "Deletion succeeded\n";
        } else{
            cout << "Deletion failed\n";
        }
    } else{
        bool ok = true;
        for(int i = 0; i < a.size(); i++){
            if( (a[i] == '1' && b[i] == '1') ||
                (a[i] == '0' && b[i] == '0')){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << "Deletion succeeded\n";
        } else{
            cout << "Deletion failed\n";
        }
    }


    return 0;
}