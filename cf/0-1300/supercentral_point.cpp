#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> vi;

int main() {
    map<int, vi> x_to_y;
    map<int, vi> y_to_x;

    int n;
    cin >> n;

    int counter = 0;
    while(n--) {
        int x, y;
        cin >> x >> y;
        x_to_y[x].push_back(y);
        y_to_x[y].push_back(x);
    }

    for(auto &p : x_to_y) {
        int x1 = p.first;

        for(int y1 : p.second) {
            bool t, b, l, r;
            t = b = l = r = false;

            // check top & bottom
            for(int y2 : x_to_y[x1]) {
                if(y2 < y1) {
                    b = true;
                } else if(y2 > y1) {
                    t = true;
                }
            }

            // check left & right
            for(int x2 : y_to_x[y1]) {
                if(x2 < x1) {
                    l = true;
                } else if(x2 > x1) {
                    r = true;
                }
            }

            if(t && b && l && r)
                counter += 1;
        }
    }

    cout << counter;

    return 0;
}