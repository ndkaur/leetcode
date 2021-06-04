/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n= stones.size();
        priority_queue<int> pq(begin(stones),end(stones));
        while(pq.size()>1){
            int a = pq.top();
            pq.pop();
            int b= pq.top();
            pq.pop();
            if(a>b)
                pq.push(a-b);
        }
        return pq.empty()?0 :pq.top();
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> stones={2,7,4,1,8,1};
    int ans = sol.lastStoneWeight(stones);
    cout<<ans;
    return 0;
}