/*
 * @lc app=leetcode id=1508 lang=cpp
 *
 * [1508] Range Sum of Sorted Subarray Sums
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
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subArray;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+= nums[j];
                subArray.push_back(sum);
            }
        }
        sort(subArray.begin(),subArray.end());
        long long mod= 1000000007;
        long long sum=0;
        for(int i=left-1;i<right;i++){
            sum = (sum+ subArray[i]) % mod;
        }
        return sum;
    }
}; // o(n^2 log(n));
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,2,3,4};
    int n= 4;
    int left=1;
    int right=10;
    int ans= sol.rangeSum(nums,n,left,right);
    cout<<ans;
    return 0;
}