#include <iostream>
#include <map>
#include <algorithm>
#include <string>

const std::string BUY = "buy",
                SELL = "sell";

int stockprice = 0;
std::map<int, int> sell;
std::map<int, int, std::greater<int>> buy;

void buy_sell(){
    if(sell.empty() || buy.empty()) return;

    int bid = buy.begin()->first,
        ask = sell.begin()->first;

    if(bid >= ask){
        int m = std::min(buy[bid], sell[ask]);
        
        buy[bid] -= m;
        sell[ask] -= m;

        if(buy[bid] == 0) buy.erase(buy.begin());
        if(sell[ask] == 0) sell.erase(sell.begin());

        stockprice = ask;
        buy_sell();
    }
}

int main(){
    /*
        ask price = lowest price someone will sell
        bid price = highest price someone will buy
        stock price = last deal done

        whenever bid price is >= ask price, deal is
        established; buy order offering bid price matched
        w/ sell order demanding ask price

        print ask bid and stock price each input line

        process input:
        buy x shares at y price
        - push to buy heap
        - see if top heap of buy is >= top of sell
            if it is, buy until:
                buy is 0
                sell is 0
        sell x shares at y price
        - push to sell heap
        - see if top of sell heap is ...
    */
    int t;
    std::cin >> t;
    
    while(t--){
        stockprice = 0;
        buy.clear();
        sell.clear();

        int n;
        std::cin >> n;
        
        for(int i = 0; i < n; i++){
            std::string action, g;
            int q, p;
            std::cin >> action >> q >> g >> g >> p;
            // std::cout << "action: " << action << std::endl;
            if(action == BUY){
                buy[p] += q;
            } else if(action == SELL){
                sell[p] += q;
            } else{
                throw "Unknown action";
            }
            
            buy_sell();

            if(sell.empty()){
                std::cout << "-";
            } else{
                std::cout << sell.begin()->first;
            }
            if(buy.empty()){
                std::cout << " - ";
            } else{
                std::cout << ' ' << buy.begin()->first << ' ';
            }

            if(stockprice == 0) std::cout << '-';
            else std::cout << stockprice;

            std::cout << '\n';
        }
    }

    return 0;
}