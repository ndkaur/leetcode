/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
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
class Solution0 {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(),stones.end(),0);
        int avg= sum/2;
        vector<bool> can(avg+1);
        can[0]=1;
        for(auto stone:stones){
            for(int s=avg-stone;s>=0;s--){
                if(can[s])
                    can[s+stone] =1;
            }
        }
        for(int s=avg;s>=0;s--){
            if(can[s])
                return sum-2*s;
        }
        return -1;
    }
};

class Solution {
public:
    int ans = INT_MAX;
    int lastStoneWeightII(vector<int>& stones) {
        int sz = stones.size();
        unordered_set<int> sum={0};
        for(int i=0;i<sz;i++){
            int stone = stones[i];
            auto temp=sum;
            sum={};
            for(auto num:temp){
                sum.insert(num+stone);
                sum.insert(num-stone);
            }
        }
        for(auto s:sum){
            ans= min(ans,abs(s));
        }
        return ans;
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<int> stones={2,7,4,1,8,1};
    int ans = sol.lastStoneWeightII(stones);
    cout<<ans;
    return 0;
}