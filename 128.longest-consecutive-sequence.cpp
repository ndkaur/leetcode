/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
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
class Solution0{
public:
    int longestConsecutive(vector<int>& nums) {
        int cnt=0;
        for(int num:nums){
            int curnum = num;
            int curcnt = 1;
            while(check(nums,curnum+1)){
                curnum +=1;
                curcnt += 1;
            }
            cnt= max(cnt,curcnt);
        }
        return cnt;
    }
    bool check(vector<int>& nums, int cur){
        for(int i=0;i<nums.size();i++){
            if(nums[i]==cur){
                return true;
            }
        }
        return false;
    }
}; // time limit exceeded 

class Solution1 {
public:
    int longestConsecutive(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        if(n==0)
            return 0;
        int cnt=1;
        int curcnt=1;
        for(int i=1;i<n;i++){
            if(nums[i] != nums[i-1]){
                if(nums[i]==nums[i-1]+1){
                   curcnt +=1;
                }
                else{
                   cnt= max(cnt,curcnt);
                   curcnt =1;
               }
            }
        }    
        return max(curcnt,cnt);
    }
};// O(nlogn)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n= nums.size();
        unordered_set<int> list(nums.begin(),nums.end());
        int cnt=0;
        for(int num:list){
            if(!list.count(num-1)){
                int cur=num;
                int curcnt=1;
                while(list.count(cur+1)){
                    cur +=1;
                    curcnt +=1;
                }
                cnt= max(cnt,curcnt);
            }
        }
        return cnt;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={};
    int ans = sol.longestConsecutive(nums);
    cout<<ans;
    return 0;
}