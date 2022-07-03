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

class Solution0 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n= nums.size();
        if(n<2)return n;
        // max(first +ve , first -ve)
        return 1+ max(check(nums,0,true),check(nums,0,false));
    }
    int check(vector<int>&nums, int idx, bool increase){
        int count =0;
        for(int i=idx+1;i<nums.size();i++){
            if((increase && nums[i]>nums[idx]) || !increase && nums[i]<nums[idx])
                count = max(count,1+ check(nums,i,!increase));
        }
        return count;
    }
};

class Solution1 {
public:
    int wiggleMaxLength(vector<int>& nums){
        int n= nums.size();
        if(n<2)return n;
        vector<int> inc(n);
        vector<int> dec(n);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])
                    inc[i]= max(inc[i],dec[j]+1);
                else if(nums[i]<nums[j])
                    dec[i] = max(dec[i],inc[j]+1);
            }
        }
        return 1+max(inc[n-1],dec[n-1]);
    }
};


class Solution2 {
public:
    int wiggleMaxLength(vector<int>& nums){
        int n= nums.size();
        if(n<2)return n;
        vector<int> inc(n);
        vector<int> dec(n);
        inc[0]=dec[0]=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                inc[i]=dec[i-1]+1;
                dec[i]=dec[i-1];
            }
            else if(nums[i]<nums[i-1]){
                dec[i]=inc[i-1]+1;
                inc[i]=inc[i-1];
            }
            else{
                dec[i]=dec[i-1];
                inc[i]=inc[i-1];
            }
        }
        return max(dec[n-1],inc[n-1]);
    }
};


//  recursion -> time limit exceeded 
// tc-> O(2^n)   sc->O(n)

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums){
        int n= nums.size();
        if(n<2) 
            return n;
        vector<int> temp;
        for(int i=1;i<n;i++){
            int diff= nums[i]-nums[i-1];
            if(diff!=0)
                temp.push_back(diff);
        }
        return 1+f(0,-1,temp); // cause temp is a diffrence array and one len gets reduced while finding diff
    }
    int f(int idx, int prev, vector<int>& temp){
        int n= temp.size();
        if(idx==n) 
            return 0;
        int not_take= 0+ f(idx+1,prev,temp);
        int take=0;
        if(prev==-1 || (temp[prev]>=0 && temp[idx]<0) || (temp[prev]<0 && temp[idx]>=0))
            take= 1+ f(idx+1, idx, temp);
        return max(take, not_take);
    }
};

//  memoization 
//  tc-> O(n*n)  sc->O(n*n)+ O(n)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums){
        int n= nums.size();
        if(n<2) 
            return n;
        vector<int> temp;
        for(int i=1;i<n;i++){
            int diff= nums[i]-nums[i-1];
            if(diff!=0)
                temp.push_back(diff);
        }
        vector<vector<int>> dp(n, vector<int>(n+1,-1)); // prev is -1 so one right shift of indexes 
        return 1+f(0,-1,temp,dp);
    }
    int f(int idx, int prev, vector<int>& temp, vector<vector<int>>& dp){
        int n= temp.size();
        if(idx==n) 
            return 0;

        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];

        int not_take= 0+ f(idx+1,prev,temp,dp);
        int take=0;
        if(prev==-1 || (temp[prev]>=0 && temp[idx]<0) || (temp[prev]<0 && temp[idx]>=0))
            take= 1+ f(idx+1, idx, temp,dp);
        return dp[idx][prev+1]=max(take, not_take);
    }
};

//  tabulation 
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums){
        int n= nums.size();
        if(n<2) 
            return n;
        vector<int> temp;
        for(int i=1;i<n;i++){
            int diff= nums[i]-nums[i-1];
            if(diff!=0)
                temp.push_back(diff);
        }
        vector<vector<int>> dp(n+1, vector<int>(n+1,0)); // prev is -1 so one right shift of indexes 
        
        for(int idx=n-1;idx>=0;idx--){
            for(int prev=idx-1; prev>=-1; prev--){
                int len = 0+ dp[idx+1][prev+1];
                // int take =0;
                if(prev == -1 || (temp[prev]>=0 && temp[idx]<0) || (temp[prev]<0 && temp[idx]>=0)){
                    len = max(len,1 + dp[idx+1][idx+1]);
                }
                dp[idx][prev+1] = len;
            }
        }
        return 1+dp[0][-1+1];
    }
};


int main(){
    Solution sol;
    vector<int> nums={1,7,4,9,2,5};
    int ans = sol.wiggleMaxLength(nums);
    cout<<ans;
    return 0;
}