/*
 * @lc app=leetcode id=1470 lang=cpp
 *
 * [1470] Shuffle the Array
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
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int j = n;
        int i = 0;
        while(j<nums.size()){
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            if(i<n)
                i++; 
            if(j<nums.size())
                j++;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[i+n]);
        }
        return ans;
    }
};

// @lc code=end


int main(){

    return 0;
}