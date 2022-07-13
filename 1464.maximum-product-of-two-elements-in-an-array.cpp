/*
 * @lc app=leetcode id=1464 lang=cpp
 *
 * [1464] Maximum Product of Two Elements in an Array
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

//  best sort -> O(nlogn)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        int ans = (nums[n-1]-1)*(nums[n-2]-1);
        return ans;
    }
};

//  using priority queue 
//  pq push , pop -> O(logn)
//  top ->O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        for(int n:nums)
            pq.push(n);
        int p1 = pq.top()-1;
        pq.pop();
        int p2= pq.top()-1;
        int ans= p1*p2;
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,5,4,5};
    int ans = sol.maxProduct(nums);
    cout<<ans;
    return 0;
}