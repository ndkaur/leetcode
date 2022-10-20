/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
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

// o(n log n)
class Solution {
public:
    string frequencySort(string s) {
        int n= s.size();
        map<char,int> mp;
        for(auto ch:s){
            mp[ch]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto itr: mp){
            pq.push({itr.second, itr.first});
        }
        string ans;
        while(pq.size()){
            auto t = pq.top();
            while(t.first){
                ans += t.second;
                t.first--;
            }
            pq.pop();
        }
        return ans;
    }
}; 

// @lc code=end


int main(){

    return 0;
}