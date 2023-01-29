#include <iostream>
#include <vector>

using namespace std;

#define lsb(S) (S & (-S))

typedef long long ll;
typedef vector<ll> vll;

class FenwickTree {
    private: 
        vll ft;
    public:
        FenwickTree(int m) {ft.assign(m + 1, 0);}
    ll rsq(int j) {
        ll sum = 0;

        for(; j > 0; j -= lsb(j)) {
            sum += ft[j];
        }

        return sum;
    }
    void update(int i, ll delta) {
        for(; i < ft.size(); i += lsb(i)) {
            ft[i] += delta;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, q;
    scanf("%d%d\n", &n, &q);

    FenwickTree FT = FenwickTree(n);

    while(q--) {
        char o;
        char op;
        scanf("%c ", &op);

        if(o == '+') {
            int i;
            ll delta;
            scanf("%d %lld\n", &i, &delta);

            FT.update(i + 1, delta);
        } else if(o == '?') {
            int i;
            scanf("%d\n", &i);
            printf("%lld\n", FT.rsq(i));
        }
    }
}