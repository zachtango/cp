#include <iostream>
#include <cmath>
#include <set>

typedef long long ll;

int main() {

    ll n;

    std::cin >> n;

    std::set<ll> divisors;
    ll n_sq_rt = std::sqrt(n) + 2;

    for(ll i = 1; i < n_sq_rt; i++) {
        if( (n % i) == 0 ) {
            divisors.insert(i);
            divisors.insert(n / i);
        }
    }

    for(auto num : divisors) {
        std::cout << (num - 1) << ' ';
    }
    
    return 0;
}