#include <iostream>
#include <vector>

using namespace std;

#define NUM_STUDENTS 20

int solve(vector<int> &heights){
    int counter = 0;
    int i = 1;
    int l = 0;
    while(i < NUM_STUDENTS){
        int j = i;
        int elem = heights[i];
        
        while(j > 0 && heights[j - 1] > elem){
            counter += 1;
            heights[j] = heights[j - 1];
            j -= 1;
        }
        heights[j] = elem;

        i += 1;
    }

    return counter;
}

int main(){

    int p, k;

    cin >> p;

    while(p--){
        cin >> k;

        vector<int> heights;
        for(int i = 0; i < NUM_STUDENTS; i++) {
            int h;
            cin >> h;
            heights.push_back(h);
        }

        cout << k << ' ';
        cout << solve(heights) << endl;
    }

    return 0;
}