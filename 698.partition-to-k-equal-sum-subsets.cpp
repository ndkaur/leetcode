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


class Solution0 { //O(2^(n*k))
public:
    bool check(vector<int>& nums, int k, int target, int idx, int curSum, vector<int>& visited){
        int n = nums.size();

        if(k==1)
            return true;

        if(curSum==target)// one subset found check for remaining k
            return check(nums, k-1, target, 0, 0, visited);
        
        for(int i=idx; i<n; i++){
            if(visited[i] || curSum+nums[i]>target)
                continue;
            
            // take it then
            visited[i]=1;
            if(check(nums, k, target, i+1, curSum+nums[i], visited)){
                return true;
            }
            visited[i] = 0;    
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
       
        int tsum = 0;
        for(int num:nums){
            tsum+=num;
        }

        if(tsum%k!=0 || n<k)
            return false;

        int target = tsum/k;
        // k will change , cur sum will change 
        // we cant change target sum cause we need to find other subsets also
        // we cant take same numbers again 
        vector<int> visited(n,0);

        // to avoid tle sort
        sort(nums.begin(), nums.end(), greater<int>());

        return check(nums, k, target, 0, 0, visited);
    }
};


class Solution1 {
public:
    bool search(int start, vector<int>& nums, vector <bool> &used, int subsetSum, int k, int targetSubsetSum) {
        if(k == 1) return true;
        
        bool ans = false;
        for(int i = start; i < nums.size(); i++) {
            if(!used[i]) { // it is not visited 
                used[i] = true; 
                int newSubsetSum = subsetSum + nums[i];
                if(newSubsetSum == targetSubsetSum) {
				    // last bucket is filled, start filling a new bucket: hence subsetSum = 0 and k = k - 1 
                    ans = ans || search(0, nums, used, 0, k-1, targetSubsetSum);
                }
                else if(newSubsetSum < targetSubsetSum) {
				    // current bucket is not full so pass subsetSum as it is
                    ans = ans || search(i + 1, nums, used, newSubsetSum, k, targetSubsetSum);
                }
                // backtrack 
                used[i] = false;
            }
        }
        
        return ans;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int tSum = 0;
        for(const auto x : nums) tSum += x;
        
        if(tSum % k != 0) return false; // cannot divide into k-equal subsets
        
        int targetSubsetSum = tSum/k;
        
        vector<bool> used(nums.size(), false); // visited
        // idx, nums, visited, cursum , k , target
        return search(0, nums, used, 0, k, targetSubsetSum);
    }
};

// above code take alot of time so we need to use bit masking dp 

class Solution { //O(k*2^N)
public:
    bool check(vector<int>& nums, int target, int curSum, int maskidx, vector<int>& dp){
        int n = nums.size();
        int sz = (1<<n);

        // when all the elemts are visited
        if(maskidx == (1<<n)-1)
            return true;
        
        if(dp[maskidx]!=-1)
            return dp[maskidx];
        
        bool ans = false;
        for(int i=0; i<n; i++){
            // if the element is not visited before 
            if(!(maskidx & (1<<i))){
                int newSum =  curSum + nums[i];

                if(newSum==target){ // target fomed, bucket is filled
                    ans = ans || check(nums, target, 0, maskidx | (1<<i), dp);
                }
                else if(newSum < target){ // curr bucket has space for elemts
                    ans = ans || check(nums, target, newSum, maskidx | (1<<i), dp);
                }
            }
        }
        return dp[maskidx] = ans;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
       
        int tsum = 0;
        for(int num:nums){
            tsum+=num;
        }

        if(tsum%k!=0 || n<k)
            return false;

        int target = tsum/k;

        int sz = (1<<n);
        vector<int> dp(sz,-1);
        
        int maskidx = 0;
        return check(nums, target, 0, maskidx, dp);
    }
};


class Solution { //O(2^(n*k))
public:
    bool check(vector<int>& nums, int target, int curSum, int maskidx, vector<int>& dp){
        int n = nums.size();
        int sz = (1<<n);

        // when all the elemts are visited
        // 2^n -1  all the bits becomes 1 
        if(maskidx == (1<<n)-1)
            return true;
        
        if(dp[maskidx]!=-1)
            return dp[maskidx];
        
        bool ans = false;
        for(int i=0; i<n; i++){
            int newMask = maskidx | (1<<i);
            // if the element is unsed
            if(maskidx!=newMask){
                int newSum =  curSum + nums[i];

                if(newSum==target){ // target fomed, bucket is filled
                    ans = ans || check(nums, target, 0, maskidx | (1<<i), dp);
                }
                else if(newSum < target){ // curr bucket has space for elemts
                    ans = ans || check(nums, target, newSum, maskidx | (1<<i), dp);
                }
            }
        }
        return dp[maskidx] = ans;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
       
        int tsum = 0;
        for(int num:nums){
            tsum+=num;
        }

        if(tsum%k!=0 || n<k)
            return false;

        int target = tsum/k;

        int sz = (1<<n);
        vector<int> dp(sz,-1);
        
        int maskidx = 0;
        return check(nums, target, 0, maskidx, dp);
    }
};
//       0 1 2 3 4 5 6
// eg:- {4,3,2,3,5,2,1}
// k= 4 ,
//  total sum = 20  , 20/4 = 5  target = 5
//  vi dp (1<<n) = 2^n  , mask =0
//  check ( mask ,cursum)

//  check (0, 0) ->
//  i=0  check if unused -> mask != newmask  , mask =0 , newmask = mask | 1<<i = 0 | 1 = 1 , 1!=0 
// i= 0, sum = 4  , 4<5 so take and check for more -> 

//  check( mask=1, sum =4)

// i=0 , mask = 1 , new mask = 1==1 , alreday position used
// i=1 , mask =1 , new mask = 1 | 10 = 10 , 1!=10  so can use 
//     sum = 4+nums[1] = 4+3 = 7 no 
// i=2  , 4+2 = 6 no 
//  i=3  4+3 = 7  no
// i=4 4+5  no
//  i=5 4+2 = no 
//  i=6 , 4+1 = 5 == target so yes ,  now find other subsets, mask will reprsent the position idx we used as 1 so 
//  mask = 1 | (1<<6) = 1 | 1000000 =  1000001

//  check(sum=0, mask = 1000001 ) 
// i=0 alread used 
//  i=1 sum = 3 < target  so -> mask = 1000001 | 10 = 1000011  check(sum = 3, mask)
//  check(sum = 3, mask)
//  i=0 used 
//  i=1 used 
//  i=2 3+2 = 5 == target  so -> mask = 1000111  , check(0, mask)

//       0 1 2 3 4 5 6
// eg:- {4,3,2,3,5,2,1}
//  check(0, 1000111)
//  i=0, used
//  i=1, used
//  i=2, used
//  i=3 sum = 3 ,  check(3, 1001111) 

// check(3, 1001111)  
// i=1 , 2,3, used 
//  i=4 -> 3+5 no 
//  i=5 -> 3+2 = 5 == target  , mask = 1101111  , check(0, mask)

//  check(0, 1101111)
//  i=0, 1, 2,3  used
//  i=4 = 5== target  mask = 1111111   , check(0, mask)

//  check stats , condition => mask== (1<<n)-1 
//  n= 7 , 1<<7 = 10000000  - 1 = 01111111
//   mask =     1111111
//   1<<n -1 = 01111111   both same , so we visited all bits of all numbers 
// return true













// @lc code=end


int main(){
    Solution sol;
    vector<int>nums={1,2,3,4,5};
    int k=3;
    bool ans=sol.canPartitionKSubsets(nums,k);
    cout<<ans;
    return 0;
}