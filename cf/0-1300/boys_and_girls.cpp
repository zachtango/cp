#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

int main() {
    int n, m;

    fstream f;
    f.open("input.txt", ios::in);
    f >> n >> m;
    cout << n << ' ' << m << endl;
    int l = min(n, m);

    fstream fout;
    fout.open("output.txt", ios::out);
    // fout << n << ' ' << m << endl;
    for(int i = 0; i < l; i++) {
        if(n > m)
            fout << "BG";
        else
            fout << "GB";
    }

    int k;
    char c;
    if(n < m) {
        k = m - l;
        c = 'G';
    } else {
        k = n - l;
        c = 'B';
    }

    for(int i = 0; i < k; i++)
        fout << c;

    f.close();
    fout.close();

    return 0;
}