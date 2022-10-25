/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
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
// we basically find the difference of the current occurence of the num to the previous occurence of the num 

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp; // num idx 
        for(int i=0; i<n; i++){
            if(mp.find(nums[i]) != mp.end() && abs(i-mp[nums[i]]) <= k){
                return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};


// @lc code=end


int main(){

    return 0;
}