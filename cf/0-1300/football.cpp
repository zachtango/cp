#include <iostream>
#include <string>

using namespace std;

int main() {
    
    int n;
    string team1, team2;

    int score1 = 1, score2 = 0;

    cin >> n >> team1;

    for(int i = 0; i < n - 1; i++) {
        string team;
        cin >> team;

        if(team == team1) {
            score1 += 1;
        } else {
            score2 += 1;
            team2 = team;
        }
    }

    if(score1 > score2) {
        cout << team1;
    } else {
        cout << team2;
    }

    return 0;
}