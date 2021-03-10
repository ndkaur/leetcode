/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
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
class Solution0 {
public:
    int lengthOfLIS(vector<int>& nums){
        int n=nums.size();
        vector<int> list(n);
        list[0]=1;
        for(int i=1;i<n;i++){
            list[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && list[i]<list[j]+1)
                    list[i]=list[j]+1;
            }
        }
        return *max_element(list.begin(),list.end());
    } // O(n2)
};

//binary search log(n)
//travelsal of array O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums){
        int n=nums.size();
        vector<int> seq;
        seq.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(seq.back() < nums[i])
                seq.push_back(nums[i]);
            else { 
                // binary search for finding location 
                int idx = lower_bound(seq.begin(),seq.end(),nums[i])-seq.begin();
                seq[idx]=nums[i];
            }
        }
        return seq.size();
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={7,7,7,7,7,7};
    int ans=sol.lengthOfLIS(nums);
    cout<<ans;
    return 0;
}