#include <iostream>

using namespace std;

#define NUM_PIECES 5

int pieces[NUM_PIECES];

void print(){
    for(int i = 0; i < NUM_PIECES; i++) cout << pieces[i] << ' ';
    cout << endl;
}

int main(){

    for(int i = 0; i < NUM_PIECES; i++) cin >> pieces[i];

    bool sorted = false;

    bool no_swaps = true;
    do {
        no_swaps = true;
        for(int i = 0; i < NUM_PIECES - 1; i++){
            if(pieces[i] > pieces[i + 1]){
                swap(pieces[i], pieces[i + 1]);
                print();
                no_swaps = false;
            }
        }
    } while(!no_swaps);

    return 0;
}