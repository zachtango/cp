#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

void print(int a, int b) {
    if(a == b) {
        cout << a;
    } else {
        cout << a << '-' << b;
    }
}

void print_lines(vector<pii> &lines) {
    int lines_size = lines.size();
    for(int i = 0; i < lines_size - 2; i++) {
        print(lines[i].first, lines[i].second);
        cout << ", ";
    }   

    if(lines_size > 1) {
        print(lines[lines_size - 2].first, 
              lines[lines_size - 2].second);
        cout << " and ";
    }

    print(lines[lines_size - 1].first, 
          lines[lines_size - 1].second);
    cout << endl;
}

int main() {
    int n, m;

    cin >> n >> m;

    bool line[n + 1];

    for(int i = 1; i <= n; i++)
        line[i] = true;

    for(int i = 0; i < m; i++) {
        int l;
        cin >> l;
        line[l] = false;
    }

    vector<pii> yes, no;

    int i = 1;

    while(i <= n) {
        int start = i;
        bool f = line[i];
        while(i <= n && f == line[i]) {
            i += 1;
        }
        int end = i - 1;

        if(f) {
            yes.push_back({start, end});
        } else {
            no.push_back({start, end});
        }
    }

    cout << "Errors: ";
    print_lines(no);

    cout << "Correct: ";
    print_lines(yes);   

    return 0;
}