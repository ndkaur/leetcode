/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
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
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n= nums.size();
        if(n<k) return false;
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
        }
        // if remainder is 1 than not perfectly divisible so no result
        if(sum%k || k<=0) return false;
        vector<bool> visited(n,false);
        int targetsum=sum/k;
        return canpartition(nums,0,visited,k,0,targetsum);   
    }
    bool canpartition(vector<int>& nums, int start, vector<bool>& visited,int k,int currsum,int targetsum){
        if(k==1) 
            return true;
        if(currsum==targetsum)
            return canpartition(nums,0,visited,k-1,0,targetsum);
        for(int i=start;i<nums.size();i++){
            if(!visited[i] && currsum+nums[i]<=targetsum){
                visited[i]=true;
                if(canpartition(nums,i+1,visited,k,currsum+nums[i],targetsum))
                    return true;
                visited[i]=false;
            }
        }
        return false;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int>nums={4,3,2,3,2,1};
    int k=4;
    bool ans=sol.canPartitionKSubsets(nums,k);
    cout<<ans;
    return 0;
}