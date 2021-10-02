/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * [1578] Minimum Deletion Cost to Avoid Repeating Letters
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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}

// @lc code=start
class Solution{
public:
    int minCost(string s, vector<int>& cost) {
        int n= s.size();
        int tcost=0;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                tcost+= min(cost[i],cost[i+1]);
                cost[i+1]= max(cost[i],cost[i+1]);
            }
        }
        return tcost;
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<int> cost={1,2,3,4,5};
    string s="abaac";
    int ans = sol.minCost(s,cost);
    cout<<ans;
   return 0;
}