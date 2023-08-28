/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
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

// same as 3 sum but here we need to return the sum closest to target
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = nums[0]+nums[1]+nums[2]; // let it be max posssible sum

        for(int i=0; i<n; i++){
            int l = i+1;
            int r = n-1;
            while(l<r){
                int sum =  nums[i]+ nums[l] + nums[r];
                if(sum==target)
                    return sum;
                // we need closest sum so update if smaller found 
                if(abs(sum-target) < abs(ans-target))
                    ans = sum;
                if(sum<target) // we need to find the closest to target
                    l++;
                else
                    r--;
            }
            // cehcking for duplicates
            if(i+1<n && nums[i+1]==nums[i])
                continue;
        }
        return ans;
    }
};

// @lc code=end


int main(){

    return 0;
}