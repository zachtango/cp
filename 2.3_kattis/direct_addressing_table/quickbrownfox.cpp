#include <iostream>
#include <string>
#include <ctype.h>
#include <algorithm>

#define CHARS 200
#define A 'a'
#define Z 'z'

bool exists[CHARS];

int main(){
    int n;

    std::cin >> n;
    getchar();
    while(n--){
        for(int i = A; i < Z + 1; i++) exists[i] = false;

        std::string s;

        std::getline(std::cin, s);
        // std::cout << s << std::endl;
        for(char c : s) exists[tolower(c)] = true;

        std::string missing = "";
        for(int i = A; i < Z + 1; i++)
            if(!exists[i]) missing.push_back(i);
    
        if(missing.size() > 0) {
            std::cout << "missing " << missing << std::endl;
            continue; 
        }

        std::cout << "pangram\n";
    }

    return 0;
}