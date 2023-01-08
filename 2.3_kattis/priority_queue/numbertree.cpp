#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int num_nodes(int h){
    return (int) pow(2, h + 1) - 1;
}

int left_child(int i){
    return 2 * i;
}

int right_child(int i){
    return 2 * i + 1;
}

int main(){
    /*
        h of tree given
        2^(h + 1) - 1 nodes

        root = 1
        left_child(i) --> 2i
        right_child(i) --> 2i + 1

        total = process string of instructions

        node = 2^(h + 1) + 1 - (total)
    */

    int h;
    string path;

    cin >> h;

    int n = num_nodes(h);

    if(cin.eof()) {
        cout << n;
        return 0;
    }

    cin >> path;

    int i = 1; // start node at root pos
    for(char c : path){
        if(c == 'L') i = left_child(i);
        else i = right_child(i);
    }

    cout << (n - i + 1);

    return 0;
}
