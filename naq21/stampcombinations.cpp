/*
BEGIN ANNOTATION
PROBLEM URL: https://open.kattis.com/problems/stampcombinations
TAGS: prefix sum
EXPLANATION:
You can either pull stamps from only the left, only the right, or both the left or right. 
We can store the amount of stamps you're able to pull from the left as a set of prefix sums, and also the right as a set of prefix sums. 
For each query, we test whether you can get the number of stamps by pulling stamps only from the left, only from the right, or from both. 
If none of these are the case, this query (q number of stamps) cannot be achieved from the clusters given. 
There is an edge case for q = 0 stamps, where it's always possible, so we check for that first. 
This solutions is O(mn) if using a hashmap to store the prefix sums; 
however, my solution used a C++ set, so the time complexity is O(mnlogm) 
where m is the number of clusters and n is the number of queries. This time complexity is fine because m * n <= 10^7.
END ANNOTATION
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    
    int m, n;

    cin >> m >> n;

    vector<int> a(m);
    set<int> left;
    set<int, greater<int>> right;

    int sum = 0;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        sum += a[i];
        left.insert(sum);
    }

    sum = 0;
    for(int i = m - 1; i >= 0; i--) {
        sum += a[i];
        right.insert(sum);
    }

    for(int i = 0; i < n; i++) {
        int q;
        cin >> q;
        
        if(q == 0) {
            cout << "Yes\n";
            continue;
        }

        if(q > *right.begin()) {
            cout << "No\n";
            continue;
        }

        if(left.count(q) != 0 || right.count(q) != 0) {
            cout << "Yes\n";
            continue;
        }

        for(auto it = left.begin(); it != left.end(); it++) {
            int s = q - *it;

            if(s < 0) {
                cout << "No\n";
                break;
            }

            if(right.count(s) != 0) {
                cout << "Yes\n";
                break;
            }
        }
    }
    
    return 0;
}