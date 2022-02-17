/*
 * @lc app=leetcode id=2064 lang=cpp
 *
 * [2064] Minimized Maximum of Products Distributed to Any Store
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
    int minimizedMaximum(int n, vector<int>& nums) {
        int low =1;
        int high = *max_element(nums.begin(),nums.end());
        int ans=-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(possible(n,nums,mid)==true){
                ans= mid;
                high=mid-1;
            }else 
                low=mid+1;
        }
        return ans;
    }
    bool possible(int n, vector<int>& nums,int mid){
        int count=0;
        for(int i=0;i<nums.size();i++){
            count += (nums[i]/mid) + ((nums[i]%mid)!=0);
            if(count>n)
                return false;
        }
        return true;
    }
};
// @lc code=end


int main(){
    Solution sol;
    int n=6;
    vector<int> nums={11,6};
    int ans = sol.minimizedMaximum(n,nums);
    cout<<ans;
    return 0;
}