#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int A, B;
const string DROP = "DROP", TAKE = "TAKE", MOVE="MOVE";
const string ONE = "1", TWO = "2";

string take_str(int num){
    return TAKE + " " + ONE + " " + to_string(num);
}

string move_str(int num){
    return MOVE + " " + TWO + "->" + ONE + " " + to_string(num);
}

string drop_str(int num){
    return DROP + " " + TWO + " " + to_string(num);
}

void solve(const string &instr){
    /*
        3 cases for take:
            A = 0, B > 0
                move B to A
                take from A the amount you need to take
                update A
            A > 0, B = 0
                take from A the amount you need to take
                update A
            A > 0, B > 0
                take from A the amount you need to take
                update A
                if you still need to take more,
                move B to A and take from A the amount you need to take
                update A


    */
    int num;
    cin >> num;

    if(instr == DROP){
        B += num;
        cout << drop_str(num) << endl;
    } else if(instr == TAKE){
        if(A == 0 && B > 0){
            cout << move_str(B) << endl;
            cout << take_str(num) << endl;

            A = B - num;
            B = 0;
        } else if(A > 0 && B == 0){
            cout << take_str(num) << endl;
            A = A - num;
        } else if(A > 0 && B > 0){
            int num_taken = min(A, num);
            cout << take_str(num_taken) << endl;
            A = A - num_taken;

            if( num == num_taken ) return;

            cout << move_str(B) << endl;
            cout << take_str( num - num_taken ) << endl;

            A = B - (num - num_taken);
            B = 0;
        } else{
            throw "Impossible numbers for A and B";
        }
    } else{
        throw "Unknown instr";
    }
}

int main(){
    int n;
    string instr;

    while(cin >> n, n){
        A = 0, B = 0;
        for(int i = 0; i < n; i++){
            cin >> instr;
            solve(instr);
        }
        cout << endl;
    }

    return 0;
}