/*
 * @lc app=leetcode id=1413 lang=cpp
 *
 * [1413] Minimum Value to Get Positive Step by Step Sum
 */
#include "bits/stdc++.h"
using namespace std;
// #include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
// #include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        
        int sum=0;
        int ans=0;
        for(int x:nums){
            sum=sum+x;
            if(sum<ans)
                ans=sum;
        }
        return -(ans)+1;
    }
};

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int start=1;
        while(true){
            int sum= start;
            bool isValid= true;
            for(int i=0;i<nums.size();i++){
                sum+= nums[i];
                  if(sum<1){
                      isValid= false;
                      break;
                  }
            }
            if(isValid)
                return start;
            else
                start+=1;
        }
        return -1;
    }
};

// insted we just find the min negative val sum so that we take the same val as +ve and it will cover all the val less than 1 
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+= nums[i];
            ans= min(ans,sum);
        }
        return -ans+1;
    }
};


// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,2};
    int ans=sol.minStartValue(nums);
    cout<<ans;
    return 0;
}