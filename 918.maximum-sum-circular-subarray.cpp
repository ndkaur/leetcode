/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
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
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int nonCircularSum = kaden(nums);
        int tsum = 0;
        // inveting the signs
        for(int i=0; i<n; i++){
            tsum += nums[i];
            nums[i] = -nums[i];
        }

        int circularSum =  tsum + kaden(nums);
        if(circularSum==0)
            return nonCircularSum;
        return max(circularSum, nonCircularSum);
    }
    int kaden(vector<int>& nums){
        int n = nums.size();
        int cur = 0;
        int mx = INT_MIN;
        for(int i=0; i<n; i++){
            cur += nums[i];
            mx = max(mx, cur);
            if(cur<0)
                cur = 0;
        }
        return mx;
    }
};

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int mxSum = nums[0];
        int mnSum = nums[0];
        int curMx = 0;
        int curMn = 0;
        int tSum = 0; 
        for(int i=0; i<n; i++){
            curMx = max(curMx + nums[i] , nums[i]);
            mxSum = max(mxSum, curMx);

            curMn =  min(curMn + nums[i], nums[i]);
            mnSum = min(mnSum , curMn);

            tSum += nums[i];
        }
        return mxSum > 0 ? max(mxSum ,  tSum - mnSum) : mxSum;
    }
};


// @lc code=end


int main(){

    return 0;
}