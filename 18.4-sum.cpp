/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        if(!n) return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int target3= target-nums[i];
            for(int j=i+1;j<n;j++){
                int target2= target3 -nums[j];
                int front = j+1;
                int back = n-1;
                while(front<back){
                    int two_sum = nums[front]+nums[back];
                    if(two_sum <target2) front++;
                    else if(two_sum>target2) back--;
                    else {
                        vector<int> quad(4,0);
                        quad[0]=nums[i];
                        quad[1]=nums[j];
                        quad[2]=nums[front];
                        quad[3]=nums[back];
                        ans.push_back(quad);
                        // duplicate of num 3
                        while(front<back && nums[front]==quad[2])
                            front++;
                        // duplicate of num 4 
                        while(front<back && nums[back] == quad[3])
                            back--;
                    }
                }
                // duplicate of num 2 
                while(j+1<n && nums[j+1]==nums[j])
                    j++;
            }
            // duplicates of num 1
            while(i+1<n && nums[i+1]==nums[i])
                i++;
        }
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,0,-1,0,-2,2};
    int target =0;
    vector<vector<int>> ans =sol.fourSum(nums,target);
    for(auto x:ans)
        print(x);
    return 0;
}