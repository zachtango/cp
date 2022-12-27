#include <bits/stdc++.h>

const std::string PB = "push_back";
const std::string PF = "push_front";
const std::string PM = "push_middle";
const std::string GET = "get";

void balance(std::deque<int> &a, std::deque<int> &b){
    int a_size = a.size(),
        b_size = b.size();
    int d = abs(a_size - b_size);

    if(d == 1 || d == 0) return;

    if(a_size > b_size){
        b.push_front(a.back());
        a.pop_back();
    } else{
        a.push_back(b.front());
        b.pop_front();
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    /*
        deque is O(1) insertion and removal at both ends
        O(n) insertion / removal in middle
    */

    int n, k;
    std::deque<int> a, b;
    std::cin >> n;
    std::string s;

    for(int i = 0; i < n; i++){
        std::cin >> s >> k;
        int a_size = a.size(),
            b_size = b.size();

        if(s == PB){
            b.push_back(k);
        } else if(s == PF){
            a.push_front(k);
        } else if(s == PM){
            int m = (a_size + b_size + 1) / 2;
            /*
                a - 1 == b
                a + 1 == b
                a == b
            */
            
            if(m == (a_size + 1)){
                a.push_back(b.front());
                b.pop_front();
            } else if(m == (a_size - 1)){
                b.push_front(a.back());
                a.pop_back();
            }
            a.push_back(k);
        } else if(s == GET){
            if(k >= a_size){
                std::cout << b[k - a_size] << std::endl;
            } else{
                std::cout << a[k] << std::endl;
            }
        } else{
            throw "Unknown instruction";
        }

        balance(a, b);
    }

    return 0;
}