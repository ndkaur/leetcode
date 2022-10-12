/*
 * @lc app=leetcode id=2104 lang=cpp
 *
 * [2104] Sum of Subarray Ranges
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
    long long subArrayRanges(vector<int>& nums) {
        int n= nums.size();
        long ans =0;
        for(int i=0; i<n; i++){
            int mn = nums[i];
            int mx = nums[i];
            for(int j=i; j<n; j++){
                mn = min(mn, nums[j]);
                mx = max(mx, nums[j]);
                ans +=  mx -mn;
            }
        }
        return ans;
    }
};

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftmn(n,-1);
        vector<int> leftmx(n,-1);

        vector<int> rightmn(n,n);
        vector<int> rightmx(n,n);

        stack<int> stk;

        for(int i=0; i<n; i++){
            while(!stk.empty() && nums[stk.top()] >= nums[i]){
                stk.pop();
            }
            if(!stk.empty())
                leftmn[i] = stk.top();
    
            stk.push(i);
        }
        
        while(stk.size()){
            stk.pop();
        }
        
        for(int i=n-1; i>=0; i--){
            while(stk.size() && nums[stk.top()] > nums[i]){
                stk.pop();
            }
            if(!stk.empty())
                rightmn[i] = stk.top();
        
            stk.push(i);
        }

        while(stk.size()){
            stk.pop();
        }

        for(int i=0; i<n; i++){
            while(!stk.empty() && nums[stk.top()] <= nums[i]){
                stk.pop();
            }
            if(!stk.empty())
                leftmx[i] = stk.top();

            stk.push(i);
        }

        while(stk.size()){
            stk.pop();
        }

        for(int i=n-1; i>=0; i--){
            while(!stk.empty() && nums[stk.top()] < nums[i]){
                stk.pop();
            }
            if(!stk.empty())
                rightmx[i] = stk.top();
            stk.push(i);
        }

        long long ans =0;
        for(int i=0; i<n; i++){
            long long lmn = i - leftmn[i];
            long long rmn = rightmn[i] - i;
            long long lmx = i - leftmx[i];
            long long rmx = rightmx[i] - i;
            ans += (lmx * rmx - lmn * rmn) * nums[i];
        }
        return ans;
    }
};
// @lc code=end


int main(){

    return 0;
}