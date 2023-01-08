#include <iostream>
#include <string>

const int ASCII_OFFSET = 48;

/*
    throw beat 1 3 L
    throw beat 2 3 R
    throw beat 3 3 L
    beat 4 R catch 1st throw
    beat 5 L catach 2nd throw
    beat 6 R catch 3rd throw

    throw beat 1 5 L
    throw beat 2 4 R
    throw beat 3 3 L
    beat 6 catch 5 R
    beat 6 catch 4 R
    beat 6 catch 3 R

    throw beat 1 3 L
    throw beat 2 4 R
    throw beat 3 5 L
    beat 4 catch 3 R
        throw 3
    beat 6 catch 4 R
        throw 4
    beat 7 catch 3 L
        throw 3
    beat 8 catch 5 R
        throw 5
    

    
*/

int main(){
    /*
    5 4 3
    
    throw beat 1 5 --> ands on right hand (odd means switch)
    throw beat 2 4 --> lands on right hand

    at most one ball is caught and at most 
    one ball is thrown on a beat

    if a ball is caught on a beat,
    it should be thrown on the same beat
    */
    std::string p;

    std::cin >> p;

    int sum = 0;
    for(auto c : p) sum += (c - ASCII_OFFSET);

    int p_size = p.size();
    if( (sum % p_size) != 0) {
        std::cout << "invalid # balls";
        return 0;
    }

    int num_balls = sum / p_size;



    return 0;
}