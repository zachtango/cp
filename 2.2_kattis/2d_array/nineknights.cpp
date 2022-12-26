#include <iostream>
#include <utility>

using namespace std;

#define BOARD_LEN 5

char board[BOARD_LEN][BOARD_LEN];
pair<int, int> dir[8] = {
    {2, 1},
    {-2, 1},
    {2, -1},
    {-2, -1},
    {1, 2},
    {-1, 2},
    {1, -2},
    {-1, -2}
};

void print(){
    cout << "-----\n";
    for(auto row : board){
        for(int i = 0; i < 5; i++){
            cout << *(row + i) << ' ';
        }
        cout << endl;
    }
    cout << "-----\n";
}

int main(){
    int count = 0;
    
    for(int i = 0; i < BOARD_LEN; i++){
        for(int j = 0; j < BOARD_LEN; j++){

            char c;
            cin >> c;

            if(c == 'k'){
                if(board[i][j] == 'a'){
                    // cout << i << ' ' << j << endl;
                    cout << "invalid";
                    return 0;
                }

                board[i][j] = 'k';

                // calc directions knight can attack
                for(auto d : dir){
                    int x = d.first + i,
                        y = d.second + j;
                    if(x < 0 || x >= 5 || y < 0 || y >= 5) continue;

                    if(board[x][y] == 'k'){
                        // cout << x << ' ' << y << endl;
                        cout << "invalid";
                        return 0;
                    }

                    board[x][y] = 'a';
                }
                
                count += 1;
            }
        }
    }
    if(count == 9) cout << "valid";
    else cout << "invalid";

    return 0;
}
