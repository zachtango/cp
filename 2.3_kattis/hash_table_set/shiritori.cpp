#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    int n;

    std::unordered_set<std::string> words;
    std::cin >> n;

    std::string s, last_word;

    std::cin >> last_word;
    words.insert(last_word);
    n -= 1;

    int turn = 1;
    while(n--) {

        std::cin >> s;

        if(
            s[0] != last_word.back() ||
            words.count(s) != 0
        ) {
            std::cout << "Player " << ( (turn % 2) + 1 ) << " lost";
            return 0;
        }

        words.insert(s);

        last_word = s;

        turn += 1;
    }

    std::cout << "Fair Game";

    return 0;
}