/*
 * @lc app=leetcode id=950 lang=cpp
 *
 * [950] Reveal Cards In Increasing Order
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

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.rbegin(),deck.rend());
        deque<int> d;
        d.push_back(deck[0]);
        for(int i=1;i<deck.size();i++){
            d.push_front(d.back());
            d.pop_back();
            d.push_front(deck[i]);
        }
        vector<int> ans(d.begin(),d.end());
        return ans;
    }
};

// 2 3 5 7 11 13 17 
// the answer order is like 2  13   3  11  5   17   7
// for making it must be in increasing order so we use deque 
//  arrange elem in decresing order 
// 17 13 11 7 5 3 2
//  pop from back and insert in front , then add next smaller elemt in front
// i=1  13  17 
// i=2   11  17 13
// i=3    

// @lc code=end


int main(){

    return 0;
}