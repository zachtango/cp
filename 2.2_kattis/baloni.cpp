#include <iostream>


using namespace std;

int darts[1000001];

int main(){
    /*
        N balloons floating in air lined up left to right

        arrow shoots from left to right and moves at height H
        until it finds a balloon --> balloon pops and arrow shoots
        at height - 1

        pop as many balloons using as little arrows as possible

        traverse heights, if you encounter height that you haven't thrown a dart at,
        you must throw a dart at that height --> add dart to darts thrown -->
        this dart thrown gets kept track of for next balloons (it's height at height - 1)
    */

    int n;

    cin >> n;

    int counter = 0;

    for(int i = 0; i < n; i++){
        int h;
        cin >> h;

        if(darts[h] == 0){
            counter++;
        } else{
            darts[h]--;
        }

        darts[h - 1]++;
    }

    cout << counter;

    return 0;
}