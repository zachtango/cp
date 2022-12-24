#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define MAX_LEN 100

int grid[MAX_LEN][MAX_LEN];
int n, m;

bool finished(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(grid[i][j] == -1) return false;
    return true;
}

void get_adj_cells(vector<pair<int, int>> &adj_cells, int i, int j){
    pair<int, int> directions[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    
    for(auto dir : directions){
        int new_i = i + dir.first,
            new_j = j + dir.second;

        if(new_i >= 0 && new_i < n &&
            new_j >= 0 && new_j < m
        ) adj_cells.push_back({new_i, new_j});
    }
}

void ring(int r){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(grid[i][j] == -1){
                if(i == 0 || i == n - 1 || 
                    j == 0 || j == m - 1){
                    grid[i][j] = 1;
                    continue;
                }

                vector<pair<int, int>> adj_cells;
                
                get_adj_cells(adj_cells, i, j);

                for(auto cell : adj_cells){
                    if(grid[cell.first][cell.second] == r){
                        // cout << cell.first << ' ' << cell.second << endl;
                        grid[i][j] = r + 1;
                        break;
                    }
                }
            }
}

void print(int num_rings){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(num_rings >= 10){
                cout << right << setw(3) << setfill('.');
            } else{
                cout << right << setw(2) << setfill('.');
            }

            if(grid[i][j] == 0) cout << '.';
            else cout << grid[i][j];
        }
        cout << endl;
    }
}

int main(){
    cin >> n >> m;

    char c;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> c;

            if(c == '.') grid[i][j] = 0;
            else grid[i][j] = -1;
        }

    int i = 0;
    do{
        ring(i);
        i += 1;
    } while(!finished());

    print(i);

    return 0;
}