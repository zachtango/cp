#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, t, a;
    cin >> n >> t;

    vector<int> A;

    for(int i = 0; i < n; i++) {
        cin >> a;
        A.push_back(a);
    }

    sort(A.begin(), A.end());

    switch(t){
        case 1: {
            for(int i = 0; i < n; i++){
                int x = A[i];
                
                if(binary_search(A.begin(), A.end(), 7777 - x)){
                    cout << "Yes";
                    return 0;
                }
            }
            cout << "No";
            break;
        }
        case 2: {
            for(int i = 1; i < n; i++){
                if(A[i - 1] == A[i]) {
                    cout << "Contains duplicate";
                    return 0;
                }
            }
            cout << "Unique";
            break;
        }
        case 3: {
            int i = 0;
            while(i < n){
                int count = 0;
                int e = A[i];

                while(i < n && e == A[i]){
                    count += 1;
                    i += 1;
                }

                // cout << e << ' ' << count << endl;
                if(count > n / 2){
                    cout << e;
                    return 0;
                }
            }
            cout << -1;
            break;
        }
        case 4: {
            int m = n / 2;
            if(n % 2 == 0) cout << A[m - 1] << ' ' << A[m];
            else cout << A[m];
            break;
        }
        case 5: {
            for(int i = 0; i < n; i++){
                if(A[i] >= 100 && A[i] <= 999){
                    cout << A[i] << ' ';
                }
            }
            break;
        }
        default:
            throw "unknown t";
    }

    return 0;
}