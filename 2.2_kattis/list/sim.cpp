#include <iostream>
#include <deque>
#include <string>

using namespace std;

void solve(const string &s){
    deque<char> output;
    auto cursor = output.end();

    for(auto c : s){
        switch(c){
            case '<': {
                if(cursor == output.begin()) continue;
                cursor = output.erase(cursor - 1);
                break;
            }
            case '[': {
                cursor = output.begin();
                break;
            }
            case ']': {
                cursor = output.end();
                break;
            }
            default:
                cursor = output.insert(cursor, c) + 1;
        }
    }

    for(char ch : output) cout << ch;
}

int main(){
    /*
        cursor will be at an iterator
        <
            undo last character that was just typed
            when typing cursor at front, do nothing
        [
            move cursor to front of line
        ]
            move cursor to end of line

        other keys
            insert char of key at cursor position
            advance cursor 1 to right
    */
    int t;
    cin >> t;
    getchar();
    
    while(t--){
        string s;    
        getline(cin, s);

        solve(s);
        cout << endl;
    }

    return 0;
}