#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef tuple<int, string, string> t;
typedef pair<int, int> p;

/* 
    1. N tuples (integer age ^, string last_name v, string first_name ^)
*/
void sort_tuples(vector<t> v){
    sort(v.begin(), v.end(), [](const t a, const t b){
        // FIXME use C++ struct binding
        int age1, age2;
        string ln1, ln2, fn1, fn2;

        tie(age1, ln1, fn1) = a;
        tie(age2, ln2, fn2) = b;

        if(age1 == age2){
            if(ln1 == ln2){
                return fn1 < fn2;
            }

            return ln1 > ln2;
        } 
        
        return age1 < age2;
    });
}


/*
    2. N fractions (numerator / denominator) ^
*/
void sort_fractions(vector<p> v){
    sort(v.begin(), v.end(), [](const p a, const p b){
        // use a / b < c / d if and only if ad < cb
        int ad = a.first * b.second,
            cb = b.first * a.second;
        
        return ad < cb;
    });
}

