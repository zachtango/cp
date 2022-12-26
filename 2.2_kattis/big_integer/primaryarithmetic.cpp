#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define ASCII_OFFSET 48
#define BASE 10

int solve(const string &a, const string &b){
    int c = 0;
    int a_size = a.size(),
        b_size = b.size();
    int n = min(a_size, b_size);
    int num_carries = 0;

    for(int i = 0; i < n; i++){
        int x = a[a_size - i - 1] - ASCII_OFFSET;
        int y = b[b_size - i - 1] - ASCII_OFFSET;

        if( (x + y + c) >= BASE ) {
            num_carries += 1;
            c = 1;
        } else c = 0;
    }

    string f;
    int size_left;

    if(a_size > b_size){
        size_left = a_size - b_size;
        f = a;
    } else{
        size_left = b_size - a_size;
        f = b;
    }

    for(int i = size_left - 1; i >= 0; i -= 1){
        int x = f[i] - ASCII_OFFSET;

        if( (x + c) < BASE ) break;

        num_carries += 1;
    }
    
    return num_carries;
}

int main(){

    string a, b;

    while(cin >> a >> b, a != "0" || b != "0"){
        int num_carries = solve(a, b);

        if(num_carries == 0) printf("No carry operation.\n");
        else if(num_carries == 1) printf("1 carry operation.\n");
        else printf("%d carry operations.\n", num_carries);
    }

    return 0;
}