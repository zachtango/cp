#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

typedef set<pair<int, string>> sis;

map<string, vector<int>> catalog;
map<string, sis> spies;

int calc_bill(const sis& events) {
    
    auto it = events.begin();
    int bill = 0;
    while(it != events.end()) {
        // starting event
        char e = it->second[0];
        
        if(e != 'p') return -1;

        string car = it->second.substr(2);
        int purchase = catalog[car][0];
        bill += catalog[car][1];

        it++;
        while(it != events.end()) {
            e = it->second[0];
            // cout << e << ": " << bill << endl;
            if(e == 'r') {
                bill += stoi(it->second.substr(2)) * catalog[car][2];
                break;
            }

            if(e == 'p') return -1;

            // e == 'a'
            int percent = stoi(it->second.substr(2));
            bill += ceil( (double) purchase * percent / 100 );

            it++;
        }

        if(e != 'r') return -1;
        it++;
    }

    return bill;
}

void solve() {
    for(auto const &[spy, events] : spies) {
        cout << spy << ' ';
        int bill = calc_bill(events);
        if(bill == -1)
            cout << "INCONSISTENT\n";
        else
            cout << bill << '\n';
    }
}

int main() {
    /*
        list of all available types of cars
        log of events for the past year

        return list of costs for car usage for every spy

        every type of car registered w/
        - catalog price
        - cost to pick up car
        - cost of driving car per km

        event list 3 types of events:
            pick ups
            - spy pays for pick up
            returns
            - num kms driven is recorded and spy pays for kms
            accidents
            - spy pays for repairs
            - accident rated w/ severity as percentage
            - percentage of catalog price billed to spy
            - billed cost is fractional --> rounded to next int
        
        T <= 100
            n [0, 500] and m [0, 10000]
                # types of cars # of events
            n lines w/ string N, int p q and k
                p [1, 100000], q [1, 1000], k [1, 100]
                name, price, pickup price, cost per km
            m lines t [0, 100000] string S one char e
                time of event, spy, type of event
                'p' is pickup
                    string C, car picked up
                'r' is return
                    int d [0, 1000],
                        distance since last picked up by spy S
                'a' is accident
                    int s [0, 100],
                        severity of accident (percent)
        

        inconsistencies:
            'r' return, we can assume that the spy
            picked up the car before returning it
                (if there isn't any pickup action)
            
            'p' pickup, we can assume the spy
            returns the car always
                (if there isn't a return after,
                price is inconsistent)

            'a' accident, spy must've bought car
            and spy will return it
                (if there is a return after, 
                then can calculate,
                otherwise inconsistent)
        
        have list of list
        spy names : list of events

        sorted by spy names alphabetically
        list of events sorted by time

        for each list of events:
            while true:
                3 starting events to encounter:
                'p' - good
                    - until you get to an r
                    - if p encountered, inconsistent
                    - calculate accumulated accidents
                'r' - inconsistent

                'a' - inconsistent
    */

    int t;
    cin >> t;

    while(t--) {
        catalog.clear();
        spies.clear();

        int n, m;
        cin >> n >> m;

        while(n--) {
            string car;
            int p, q, k;

            cin >> car >> p >> q >> k;

            catalog[car] = {p, q, k};
        }

        while(m--) {
            int t;
            string spy, event;
            cin >> t >> spy;
            getchar();
            getline(cin, event);

            spies[spy].insert({t, event});
        }

        solve();
    }

    return 0;
}