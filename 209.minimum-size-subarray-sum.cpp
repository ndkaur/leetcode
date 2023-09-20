/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
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
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        int mn = INT_MAX;
        int i =0;
        int j=0;
        while(j<n){
            sum += nums[j];
            while(sum>=target){
                mn = min(mn, j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return mn== INT_MAX ? 0 :mn;
    }
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i =0;
        int ans = INT_MAX;
        int sum =0;
        for(int j=0; j<n; j++){
            sum+=nums[j];
            while(sum>=target){
                sum= sum - nums[i];
                // calculate the ans bf=efore changing thw window size
                ans = min(ans, j-i+1);
                // ans calculated now change window size to smaller than target value
                i++;
            }
        }
        return ans==INT_MAX ? 0 : ans;
    }
};
// @lc code=end


int main(){

    return 0;
}