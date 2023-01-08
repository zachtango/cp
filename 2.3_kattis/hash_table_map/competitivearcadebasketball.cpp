#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, int> score;

int main() {
    /*
        n participants, 
        p points required to win contest,
        m number of lines with player names and points
        next n lines contain name of participants
        next m lines contain name of a participant and points
    */

    int n, p, m;

    std::cin >> n >> p >> m;
    std::string s;

    for(int i = 0; i < n; i++) std::cin >> s;

    bool no_winner = true;
    int points;
    for(int i = 0; i < m; i++) {
        std::cin >> s >> points;

        score[s] += points;
        if(score[s] >= p) {
            std::cout << s << " wins!\n";
            score[s] = -1000000;
            no_winner = false;
        }
    }

    if(no_winner) std::cout << "No winner!\n";

    return 0;
}