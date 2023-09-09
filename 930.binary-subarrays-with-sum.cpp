/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
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
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal-1);
    }
    int atmost(vector<int>& nums, int goal){
        int n= nums.size();
        if(goal<0)
            return 0;
        int l = 0; 
        int r = 0;
        int cnt = 0;
        int sum = 0;
        while(r<n){
            sum += nums[r];
            while(sum > goal){
                sum = sum - nums[l];
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
};

// subaray with sum at most k =2  14 subarays 
// subarray with sum at most k -1 = 2-1 = 1  => 10 subarrays 
// so the ans is 14-10 =  4;
// @lc code=end


class Solution0 {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        unordered_map<int, int> mp;
        int ans = 0, sm = 0;
        for (int i = 0; i < n; i++) {
            sm += nums[i];
            if (sm == goal) ans++;
            if (mp.count(sm - goal)) {
                ans += mp[sm - goal];
            }
            mp[sm]++;
        }

        return ans;
    }
};

int main(){

    return 0;
}