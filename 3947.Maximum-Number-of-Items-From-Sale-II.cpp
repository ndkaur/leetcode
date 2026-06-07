#include "bits/stdc++.h"
using namespace std;
// #include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}



class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size(); // factor, price
        vector<int> fact(n+1,0);
        long long mn_price = LLONG_MAX;
        // tle 
        // for(int i=0; i<n; i++){ // cnt increase if i divide j, j%i 4%2 
        //     mn_price = min(mn_price, items[i][1]);
        //     for(int j=0; j<n; j++){ 
        //         // this will include the self factor cnt also 
        //         if(items[j][0] % items[i][0]==0){
        //             fact[i]++;
        //         }
        //     }
        // }
        for(auto& item:items){
            int factor = item[0];
            long long price = item[1];
            if(factor<=n)
                fact[factor]++;
            if(price<mn_price)
                mn_price = price;
        }

        vector<int> fact_cnt(n+1,0);
        for(int f=1; f<=n; f++){
            for(int multiple=2*f; multiple<=n; multiple+=f){
                fact_cnt[f] += fact[multiple];
            }

            if(fact[f]>0){ // not adding the self factor 5-> 2 factor , adding one (5,20) (5,17)
                fact_cnt[f] += (fact[f]-1);
            }
        }


        // (5,20) (6,6) budget =24
        //  20 ->1buy +1 free -> pair with factor but we dont choose it 
        //  6-> 4 buy 
        vector<pair<long long,int>> premium; // price < mn*2
        for(int i=0; i<n; i++){
            int factor = items[i][0];
            long long price = items[i][1];
            int cnt = fact_cnt[factor];

            if(cnt>0 && price<2*mn_price){ // then its a premium pair 
                premium.push_back({price, cnt});
            }
        }

        // we want that premium deal with min price
        sort(premium.begin(), premium.end());
        long long total = 0;

        for(auto pre:premium){
            if(budget<=0)
                break;
            long long price = pre.first;
            int cnt = pre.second;
            // (8,2) budget=35 , 35/8 = 4= can_buy_total
            // but we only have 2 cnt so min(cnt, can_buy_totoal)
            int can_buy_total = budget/price;
            int can_buy = min(cnt, can_buy_total);

            total += can_buy*2; // 1 free with buy 1 
            budget = budget-(price*can_buy);
        }

        // if in the end we still have some buget , can buy minum 
        total += budget/mn_price;
        return total;
    }
};



int main(){

    return 0;
}