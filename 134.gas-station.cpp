/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_cost = 0;
        int total_gas = 0;
        for(int i =0; i<n; i++){
            total_cost += cost[i];
            total_gas += gas[i];
        }
        if(total_cost > total_gas){
            return -1;
        }
        int idx =0;
        int cur_gas =0;
        for(int i = 0; i<n; i++){
            if(cur_gas < 0){
                cur_gas =0;
                idx =i;
            } 
            cur_gas += gas[i] - cost[i];
        }
        return idx;
    }
};
// @lc code=end


int main(){

    return 0;
}