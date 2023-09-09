/*
 * @lc app=leetcode id=1695 lang=cpp
 *
 * [1695] Maximum Erasure Value
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

// sliding window 
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=0;
        int sum =0;
        int mx =0;
        map<int,int> mp;
        while(j<n){
            mp[nums[j]]++;
            sum += nums[j];
            
            while(mp[nums[j]]>1){
                mp[nums[i]]--;
                sum -= nums[i];
                i++;
            }
            mx = max(mx,sum);
            j++;
        }
        return mx;
    }
};

// @lc code=end


int main(){

    return 0;
}