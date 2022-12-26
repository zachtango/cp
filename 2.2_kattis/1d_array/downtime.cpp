#include <iostream>
#include <queue>
#include <math.h>
#include <vector>

using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> pq;
    int n, k, t;

    cin >> n >> k;

    int servers = 0;
    for(int i = 0; i < n; i++){
        cin >> t;

        if(!pq.empty()){
            // cout << "top: " << pq.top() << endl;
            while(!pq.empty() && pq.top() < t){
                pq.pop();
            }
        }

        pq.push(t + 999);

        // cout << "pq: " << pq.size() << endl;
        // cout << "servers: " << (int) ceil((double) pq.size() / k) << endl;
        servers = max(servers, (int) ceil((double) pq.size() / k));
    }

    cout << servers << endl;

    return 0;
}