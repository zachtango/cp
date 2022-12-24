#include <iostream>

using namespace std;

#define MAX_LEN 20

char room[MAX_LEN][MAX_LEN];

pair<int, int> solve(char room[MAX_LEN][MAX_LEN], int w, int l, pair<int, int> &entr){
    int dir[2];

    if(entr.first == 0){
        dir[0] = 1, 
        dir[1] = 0;
    } else if(entr.first == l - 1){
        dir[0] = -1,
        dir[1] = 0;
    } else if(entr.second == 0){
        dir[0] = 0, 
        dir[1] = 1;
    } else if(entr.second == w - 1){
        dir[0] = 0, 
        dir[1] = -1;
    } else{
        throw "Unknown entrance position";
    }

    int i = entr.first,
        j = entr.second;
    char c = room[i][j];

    while(c != 'x'){
        i += dir[0];
        j += dir[1];

        c = room[i][j];

        switch(c){
            case 'x':
                return {i, j};
            case '/':
                if(dir[0] == 1){
                    dir[0] = 0,
                    dir[1] = -1;
                } else if(dir[0] == -1){
                    dir[0] = 0,
                    dir[1] = 1;
                } else if(dir[1] == 1){
                    dir[0] = -1,
                    dir[1] = 0;
                } else{
                    dir[0] = 1,
                    dir[1] = 0;
                }
                break;
            case '\\':
                if(dir[0] == 1){
                    dir[0] = 0,
                    dir[1] = 1;
                } else if(dir[0] == -1){
                    dir[0] = 0,
                    dir[1] = -1;
                } else if(dir[1] == 1){
                    dir[0] = 1,
                    dir[1] = 0;
                } else{
                    dir[0] = -1,
                    dir[1] = 0;
                }
        }
    }

    return {-1, -1};
}

int main(){

    int w, l;
    pair<int, int> entr;
    int t = 1;
    while(cin >> w, cin >> l, w || l){
        for(int i = 0; i < l; i++){
            for(int j = 0; j < w; j++){
                cin >> room[i][j];

                if(room[i][j] == '*'){
                    entr.first = i,
                    entr.second = j;
                }
            }
        }

        pair<int, int> exit = solve(room, w, l, entr);
        room[exit.first][exit.second] = '&';

        cout << "HOUSE " << t << endl;
        for(int i = 0; i < l; i++){
            for(int j = 0; j < w; j++){
                cout << room[i][j];
            }
            cout << endl;
        }
        t += 1;
    }

    return 0;
}