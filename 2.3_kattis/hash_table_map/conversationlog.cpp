#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <iterator>

typedef std::set<std::string> ss;
typedef std::unordered_map<std::string, ss> umsss;
typedef std::unordered_map<std::string, int> umsi;

int m;
umsss user_words;
umsi word_count;

int main() {
    /*
        M num of messages
        next M lines each beginning
            user's name no more than 20 chars
            rest of line is content of user's msg
            total number of chars <= 2 * 10^6
        
        output words used by every single user
            ordered from most to least used

        keep word counter
        keep set of words for each user
        intersect all the user's sets to get shared words
            print out shared words in greatest count to least count
    */

    std::cin >> m;

    std::string s;
    for(int i = 0; i < m; i++) {
        std::string name;
        std::cin >> name;

        do {
            std::cin >> s;

            word_count[s] += 1;
            user_words[name].insert(s);
        } while(std::getchar() != '\n');
        // std::cout << name << '\n';
    }

    // get common words
    ss common_words;
    auto first = user_words.begin();
    auto second = std::next(first);

    std::set_intersection(
        first->second.begin(), first->second.end(),
        second->second.begin(), second->second.end(),
        std::inserter(common_words, common_words.begin())
    );

    ss temp;
    for(auto it = std::next(second); it != user_words.end(); it++) {
        temp.clear();

        std::set_intersection(
            common_words.begin(), common_words.end(),
            it->second.begin(), it->second.end(),
            std::inserter(temp, temp.begin())
        );

        common_words = temp;
    }

    if(common_words.size() == 0) {
        std::cout << "ALL CLEAR\n";
    } else {
        std::vector<std::string> f(common_words.begin(), common_words.end());
        sort(f.begin(), f.end(),
            [](const std::string &a, const std::string &b) {
                return word_count[a] > word_count[b];
            }
        );
        
        for(auto &w : f)
            std::cout << w << '\n';
    }

    return 0;
}