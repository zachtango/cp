#include <iostream>

#define a 'a'
#define z 'z'

int main() {
    /*
        check essay:
        - # words in [A, B]
        - for every word, # letters in [1, 15]
        - # unique words >= B / 2

        write essay:
        - ouput single line using only
        - lower case letters and spaces
        - words don't have to be from englo language
    */

   int A, B;

   std::cin >> A >> B;

   int num_words = B / 2;

   /*
        must produce B / 2 unique words
        B / 2 <= 50000
        26^4 = 456976
   */

    int counter = 0;
    for(char i = a; i <= z; i++)
        for(char j = a; j <= z; j++)
            for(char k = a; k <= z; k++)
                for(char l = a; l <= z; l++) {
                    std::cout << i << j << k << l << ' ';

                    counter += 1;

                    if(counter >= A && counter > B / 2) {
                        return 0;
                    }
                }

    return 0;
}