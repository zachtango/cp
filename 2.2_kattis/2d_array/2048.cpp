#include <iostream>
#include <vector>
#include <list>

enum direction {left = 0, up = 1, right = 2, down = 3};

using namespace std;

#define BOARD_LEN 4

int board[BOARD_LEN][BOARD_LEN];

void merge(int *v, int dir){
    /*
        case 1: no items can be merged
            move all items to left or right
        case 2: item 1 and 2 can be merged
            merge item 1 and 2
            move all items to left or right
        case 3: item 1 and 2 can be merged, item 3 and 4 can be merged
            merge item 1 and 2, merge item 3 and 4
            move all items to left or right
    */

    int new_v[BOARD_LEN] = {0, 0, 0, 0};
    int new_v_pos = 
        (dir == direction::left || dir == direction::up) ? 0 : BOARD_LEN - 1;

    int last_cell = 0;

    for(int i = 0; i < BOARD_LEN; i++){
        int pos = i;
        if( !(dir == direction::left || dir == direction::up) )
            pos = BOARD_LEN - i - 1;

        if(v[pos] == 0) continue;

        if(last_cell == 0){
            last_cell = v[pos];
            continue;
        }
        
        if(last_cell == v[pos]){
            new_v[new_v_pos] = last_cell * 2;
            last_cell = 0;
        } else{
            new_v[new_v_pos] = last_cell;
            last_cell = v[pos];
        }

        if(dir == direction::left || dir == direction::up) new_v_pos += 1;
        else new_v_pos -= 1;
    }

    if(last_cell != 0) new_v[new_v_pos] = last_cell;

    for(int i = 0; i < BOARD_LEN; i++) v[i] = new_v[i];
}

void print(){
    // cout << "--------\n";
    for(int i = 0; i < BOARD_LEN; i++){
        for(int j = 0; j < BOARD_LEN; j++){
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    
    for(int i = 0; i < BOARD_LEN; i++)
        for(int j = 0; j < BOARD_LEN; j++)
            cin >> board[i][j];

    int dir;

    cin >> dir;

    // print();

    if(dir == direction::left || dir == direction::right)
        for(int i = 0; i < BOARD_LEN; i++)
            merge(board[i], dir);
    else{
        int v[BOARD_LEN];
        for(int j = 0; j < BOARD_LEN; j++){
            for(int i = 0; i < BOARD_LEN; i++)
                v[i] = board[i][j];
            
            merge(v, dir);

            for(int i = 0; i < BOARD_LEN; i++)
                board[i][j] = v[i];
        }
    }

    print();

    return 0;
}
