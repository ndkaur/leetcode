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


class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i<n/2; i++){
            int val = nums[i]+nums[n-i-1];
            res = max(res, val);
        }
        return res;
    }
};

class Solution0 { // O(nlogn)
public:
    int minPairSum(vector<int>& nums) {
        int n  = nums.size();
        // 2 3 4 4 5 6
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = n-1;
        int mx = 0;
        while(l<r){
            int sum =  nums[l]+nums[r];
            mx = max(mx, sum);
            l++;
            r--;
        }
        return mx;
    }
};

class Solution { //O(n)
public:
    int minPairSum(vector<int>& nums) {
        int n  = nums.size();
        int mx = INT_MIN;
        int mn = INT_MAX;
        int mxsum = 0;
        vector<int> freq(100001,0);
        for(int num:nums){
            freq[num]++;
            mn = min(mn, num);
            mx = max(mx, num);
        }

        int low = mn;
        int high = mx;

        while(low<=high){
            if(freq[low]==0)
                low++;
            else if(freq[high]==0)
                high--;
            else{
                int curSum =  low+high;
                mxsum = max(mxsum , curSum);
                freq[low]--;
                freq[high]--;
            }
        }
        return mxsum;
    }
};

// 3 5 4 2 4 6
// mn , mx, sum 
// freq arr
// 3 5 4 2 6
// 1 1 2 1 1
// mn = 2
// mx = 6

// low = 2
//  high = 6
//  curr sum = 8   mx =8
//  freq 
// 3 5 4 
// 1 1 2 
// 



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