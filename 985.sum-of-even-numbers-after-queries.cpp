/*
 * @lc app=leetcode id=985 lang=cpp
 *
 * [985] Sum of Even Numbers After Queries
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
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries){
        int n = nums.size();
        vector<int> ans;
       
        for(auto que:queries){
            int val = que[0];
            int idx = que[1];

            nums[idx] += val;
            
            int sum = 0;
            for(int i=0; i<n; i++){
                if(nums[i]%2==0){
                    sum += nums[i];
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries){
        int n = nums.size();
        vector<int> ans;
        // instead of calculating sum again n again store it prior 
        int sum = 0;
        for(int i=0; i<n; i++){
            if(nums[i]%2==0)
                sum+=nums[i];
        }
        for(int i=0; i<queries.size(); i++){
            int val = queries[i][0];
            int idx = queries[i][1];
            // before adding the val if num already even then reduce sum
            if(nums[idx]%2==0)
                sum -= nums[idx];

            nums[idx] += val;

            // after adding val if sum get even then add to sum
            if(nums[idx]%2==0)
                sum += nums[idx];
            
            ans.push_back(sum);
        }
        return ans;
    }
};


// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> queries={{1,0},{-3,1},{-4,0},{2,3}};
    vector<int> A={1,2,3,4};
    vector<int> ans=sol.sumEvenAfterQueries(A,queries);
    print(ans);
    return 0;
}