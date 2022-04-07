/*
 * @lc app=leetcode id=923 lang=cpp
 *
 * [923] 3Sum With Multiplicity
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
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int,long> mp;
        long ans=0;
        for(auto i:arr) mp[i]++;
        for(auto itr1 :mp){
            for(auto itr2:mp){
                int i= itr1.first;
                int j= itr2.first;
                int k= target- i-j;
                if(!mp.count(k)) continue;
                if(i==j && j==k) // all equal then nC3
                    ans+= mp[i]* (mp[i]-1) * (mp[i]-2) /6;
                else if(i==j && j!=k) // only two are equal then nc2 * nc1
                    ans += mp[i]* (mp[i]-1) /2 * mp[k];
                else if(i<j && j<k)
                    ans+= mp[i]*mp[j]*mp[k];
            }
        }
        return ans % int(1e9+7);
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> arr={1,1,2,2,3,3,4,4,5,5};
    int target= 8;
    int ans = sol.threeSumMulti(arr, target);
    cout<<ans;
    return 0;
}