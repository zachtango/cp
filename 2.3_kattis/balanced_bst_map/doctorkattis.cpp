#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <utility>

using namespace std;

#define CLINIC_EMPTY "The clinic is empty"

typedef pair<int, int> pii;

struct Cat {
    string name;
    int infection_level;
    int arrived;

    bool operator<(const Cat &c) const {
        if(this->infection_level == c.infection_level)
            return this->arrived < c.arrived;
        return this->infection_level > c.infection_level;
    }

    Cat(string n, int i, int t) : 
    name(n), infection_level(i), arrived(t) {}
};

unordered_map<string, pii> values;
set<Cat> cats;
int CLOCK = 0;

void arrive_at_clinic(const string &cat_name, int infection_level, int t) {
    Cat c(cat_name, infection_level, t);

    values[cat_name] = {infection_level, t};
    cats.insert(c);
}

void update_infection_level(const string &cat_name, int increase_infection) {
    Cat c(cat_name, values[cat_name].first, values[cat_name].second);

    auto it = cats.find(c);
    auto d = *it;
    cats.erase(it);
    
    d.infection_level += increase_infection;
    values[cat_name].first += increase_infection;
    cats.insert(d);
}

void treated(const string &cat_name) {
    Cat c(cat_name, values[cat_name].first, values[cat_name].second);
    cats.erase(c);
    values.erase(cat_name);
}

void query() {
    if(cats.size() == 0) {
        cout << CLINIC_EMPTY;
    } else {
        cout << cats.begin()->name;
    }
    cout << '\n';
}

void process(int instr) {
    string cat_name;
    int num;
    switch(instr) {
        case 0:
            cin >> cat_name;
            cin >> num;
            arrive_at_clinic(cat_name, num, CLOCK);
            break;
        case 1:
            cin >> cat_name;
            cin >> num;
            update_infection_level(cat_name, num);
            break;
        case 2:
            cin >> cat_name;
            treated(cat_name);
            break;
        case 3:
            query();
            break;
        default:
            throw "Unknown instr";
    }
    CLOCK += 1;
}

int main() {
    /*
        arrivate at clinic(catName, infectionLevel)
        - 0 catName, infectionLevel
        update infection level(catName, increaseInfection)
        - 1 catName, increaseInfection
        treated(catName)
        - 2 catName
        query, print highest inf or The clinic is empty
        - 3
    */

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int instr;

        cin >> instr;

        process(instr);
    }

    return 0;
}