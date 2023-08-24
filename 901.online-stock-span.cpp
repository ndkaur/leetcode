/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */
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

// @lc code=start

class StockSpanner {
public:
    stack<pair<int,int>> stk; // monotonic decr stack
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        // breaking incresing condition
        while(stk.size() && stk.top().first <= price){
            span += stk.top().second;
            stk.pop();
        }
        stk.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end


int main(){

    return 0;
}