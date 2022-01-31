/*
 * @lc app=leetcode id=1877 lang=cpp
 *
 * [1877] Minimize Maximum Pair Sum in Array
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
class Solution0 {
public:
    int minPairSum(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        // 2 3 3 5
        int sum=INT_MIN;
        int j=n-1;
        for(int i=0;i<n/2;i++){
            sum = max(sum,nums[i]+nums[j]);
            j--;
        }
        return sum;
    }
};


class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n= nums.size();
        Csort(nums);
        // 2 3 3 5
        int sum=INT_MIN;
        int j=n-1;
        for(int i=0;i<n/2;i++){
            sum = max(sum,nums[i]+nums[j]);
            j--;
        }
        return sum;
    }
    void Csort(vector<int>& nums){
        int n= nums.size();
        int mx= *max_element(nums.begin(),nums.end());
        vector<int> count(mx+1,0);
        for(int i:nums)
            count[i]++;
        int i=0;
        for(int j=0;j<count.size();j++){
            int c= count[j];
            while(c--){
                nums[i]=j;
                i++;
            }
        }
    }
};
// @lc code=end



int main(){
    Solution sol;
    vector<int> nums={3,5,2,3};
    int ans= sol.minPairSum(nums);
    cout<<ans;
    return 0;
}