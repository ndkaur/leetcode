/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
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
class Solution0 { // o(n)
public:
    int longestOnes(vector<int>& nums, int k) {
        int n= nums.size();
        int zcount=0;
        int start=0;
        int end=0;
        int ans=0;
        while(end<n){
            if(nums[end]==1){
                end++;
            } else{ // end value is 0 
                if(zcount<k){
                    zcount++;
                    end++;
                }
                else{ // zcount>=k
                    while(zcount==k){
                        if(nums[start]==0)
                            zcount--;
                        start++;
                    }
                }
            }
            ans= max(ans,end-start);
        }
        return ans;
    }
};

class Solution { 
public:
    int longestOnes(vector<int>& nums, int k) {
        int low=0;
        int high= nums.size();
        int ans =0;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(check(nums,k,mid)==true){
                ans = mid;
                low=mid+1;
            }
            else 
                high= mid-1;
        }
        return ans;
    }
    bool check(vector<int>&nums,int k, int mid){
        int ocount=0;
        int zcount=0;
        for(int i=0;i<mid;i++){
            if(nums[i]==1)
                ocount++;
            else 
                zcount++;
        }
        if(zcount<=k) return true;
        for(int i=mid;i<nums.size();i++){
            if(nums[i]==1) 
                ocount++;
            else 
                zcount++;
            if(nums[i-mid]==0)
                zcount--;
            else 
                ocount--;
            if(zcount<=k)
                return true;
        }
        return false;
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,1,1,0,0,0,1,1,1,1,0};
    int k= 2;
    int ans = sol.longestOnes(nums,k);
    cout<<ans;
    return 0;
}