n/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
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
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n=nums.size();
        vector<pair<long long ,long long>> v(n);
        for(int i=0;i<n;i++){
            v[i].first = nums[i];
            v[i].second=i;
        }
        sort(v.begin(),v.end());
    
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n && abs(v[i].first - v[j].first)<=t;j++){
                if(abs(v[i].first-v[j].first)<=t){
                    if(abs(v[i].second-v[j].second)<=k){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,0,1,1};
    int t=2;
    int k=1;
    bool ans=sol.containsNearbyAlmostDuplicate(nums,k,t);
    cout<<ans;
    return 0;
}