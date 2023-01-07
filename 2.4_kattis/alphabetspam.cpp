#include <iostream>
#include <string>

#define CHARS 126

int count[CHARS + 1];

int main(){
    std::string s;
    std::cin >> s;

    for(char c : s) count[c] += 1;

    int total = s.size(),
        w_chars = count['_'],
        l_chars = 0,
        u_chars = 0,
        s_chars = 0;

    // lower
    for(int i = 97; i < 97 + 26; i++) l_chars += count[i];

    // upper
    for(int i = 65; i < 65 + 26; i++) u_chars += count[i];

    s_chars = total - w_chars - l_chars - u_chars;

    // printf(
    //     "%d, %d, %d, %d, %d\n",
    //     total, w_chars, l_chars, u_chars, s_chars
    // );

    printf("%.7f\n", (double) w_chars / total);
    printf("%.7f\n", (double) l_chars / total);
    printf("%.7f\n", (double) u_chars / total);
    printf("%.7f\n", (double) s_chars / total);

    return 0;
}
