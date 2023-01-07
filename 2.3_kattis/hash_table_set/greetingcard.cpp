#include <iostream>
#include <unordered_set>
#include <vector>

#define LEN 2018

typedef long long ll;
typedef std::pair<ll, ll> pll;
typedef std::vector<int> vi;

vi X, Y;
std::unordered_set<ll> points;
int counter = 0;
int directions[12][2] = {
    {0, 2018},
    {0, -2018},
    {2018, 0},
    {-2018, 0},
    {1118, 1680},
    {1118, -1680},
    {-1118, 1680},
    {-1118, -1680},
    {1680, 1118},
    {-1680, 1118},
    {1680, -1118},
    {-1680, -1118},
};

int n;

/*
    get points (x, y)
    where x in [0, 2018] and y in [0, 2018]
    such that x^2 + y^2 = 2018^2
*/
void print_neighbors() {
    for(int x = 0; x <= LEN; x++)
        for(int y = 0; y <= LEN; y++) {
            int s = x * x + y * y;
            
            if( s == (LEN * LEN) ) 
                std::cout << x << ' ' << y << std::endl;
        }
}

ll get_key(ll x, ll y) {
    return (x << 32) | y;
}

void check_neighbors(ll x, ll y) {
    for(auto dir : directions) {
        ll new_x = x + *dir,
            new_y = y + *(dir + 1);
        
        if(points.count(get_key(new_x, new_y)) != 0)
            counter += 1;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    /*
        1. store points in unordered_set (10^5 points)
        2. iterate through points in unordered_set
            a. check 12 neighbors relative to the current point
            b. if a neighbor exists in the unordered_set, this is a line segment
            c. store the line segment (pair of points) in an unordered_set to keep track of known line segments
                - store pair as a string (x1, y1) (x2, y2) where x1 <= x2
    */
    // print_neighbors();

    std::cin >> n;

    while(n--) {
        int x, y;
        std::cin >> x >> y;

        X.push_back(x);
        Y.push_back(y);
        points.insert(get_key(x, y));
    }

    int l = X.size();

    for(int i = 0; i < l; i++) {
        check_neighbors(X[i], Y[i]);
        points.erase(get_key(X[i], Y[i]));
    }

    std::cout << counter;

    return 0;
}