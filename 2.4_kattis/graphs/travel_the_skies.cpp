#include <iostream>

using namespace std;

#define K_MAX 12 + 1
#define N_MAX 8 + 2

int flight[N_MAX][K_MAX][K_MAX];
int people_at_airport[K_MAX];
int people_arrival[N_MAX][K_MAX];

/*
    1 flight a day
    can fly any day on or after suggested departure
    don't have to return to original departure airport

    k, n, m
        - k num airports
        - n number of days of flight departure window
        - m number of flights in the window
    m lines follow w/ 4 integers each
        u, flights starting location
        v, flights ending destination
        d, day on which flight flies in the window
        z, cap of flight

    kn lines
        a, airport
        b, the day
        c, num customers wishing to begin travels
        by leaving their home to their airport a
        on day b
*/

int main() {
    
    /*
        for each day, have an adjacency list
        representing the flights

        have a peoples array mapping the airport k
        to the number of peopple currntly
        at the airport

        have a mapping of days to people arriving at airport
    */

    int k, n, m;
    cin >> k >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v, d, z;
        cin >> u >> v >> d >> z;

        flight[d][u][v] = z;
    }

    for(int i = 0; i < (k * n); i++) {
        int a, d, c;
        cin >> a >> d >> c;
    
        people_arrival[d][a] = c;
    }

    for(int d = 1; d <= n; d++) {
        for(int a = 1; a <= k; a++) {
            people_at_airport[a] += people_arrival[d][a];
        }

        for(int u = 1; u <= k; u++) {
            for(int v = 1; v <= k; v++) {
                int cap = flight[d][u][v];
                if(people_at_airport[u] < cap) {
                    cout << "suboptimal";
                    return 0;
                }

                people_at_airport[u] -= cap;
                people_arrival[d + 1][v] += cap;
            }
        }
    }

    cout << "optimal";

    return 0;
}
