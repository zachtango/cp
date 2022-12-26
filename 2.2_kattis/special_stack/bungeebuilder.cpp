#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int main(){
    stack<int> H;

    /*
        process height

        3 cases:
            stack empty --> push this height and set min to height
            stack.top() >= height -->
                if min_height < this height -->
                    m = max(m, this height - min_height)
                else -->
                    min_height = this height
            stack.top() < height -->
                if min_height != stack.top()
                    m = max(m, this height - min_height)
                push this height to stack
    */

    int n;
    cin >> n;

    int h;
    cin >> h;

    int m = 0;
    int min_height = h;

    H.push(h); 
    for(int i = 0; i < n - 1; i++){
        cin >> h;
        if(H.top() >= h){
            if(min_height < h) m = max(m, h - min_height);
            else min_height = h;
        } else{
            if(min_height != H.top()) m = max(m, H.top() - min_height);
            min_height = h;
            H.push(h);
        }
    }

    cout << m;

    return 0;
}