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


class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n=nums.size(), p=pattern.size();
        bool f=1;
        int ans=0;
        for(int i=0;i<n-p;i++){
            int a=i; f=1;
            for(int j=0;j<p;j++){
                if((pattern[j]==1 && nums[i]>=nums[i+1]) || 
                   (pattern[j]==0 && nums[i]!=nums[i+1]) || 
                   (pattern[j]==-1 && nums[i]<=nums[i+1])){
                        f=0;
                       break;
                    }
                i++;
            }
            if(f==1)
                ans++;
            i=a;
        }
        return ans;
    }
};

class Solution {
public:
    int f(int i, int j, vector<int>& pattern, vector<int>& nums,vector<vector<int>>&dp){
        int n = nums.size();
        int p = pattern.size();
        if(j==p) // pattern reached end -> subarray formed 
            return 1;
        if(i==n-1)
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if((pattern[j]==0 && nums[i]==nums[i+1]) || (pattern[j]==1 && nums[i]<nums[i+1]) || (pattern[j]==-1 && nums[i]>nums[i+1]))
            return dp[i][j] =  f(i+1,j+1, pattern, nums, dp);
        
        return dp[i][j]  = 0;
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int cnt =0;
        vector<vector<int>> dp(n, vector<int>(pattern.size(),-1));
        for(int i=0; i<n; i++){
            cnt += f(i, 0, pattern, nums, dp);
        }
        return cnt;
    }
};



int main(){

    return 0;
}