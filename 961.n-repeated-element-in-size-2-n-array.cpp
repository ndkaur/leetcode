/*
 * @lc app=leetcode id=961 lang=cpp
 *
 * [961] N-Repeated Element in Size 2N Array
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
    int repeatedNTimes(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int> mp;
        for(int n:nums)
            mp[n]++;
        for(auto& it:mp){
            if(it.second>1)
                return it.first;
        }
        return 0;
    }
};
// @lc code=end


int main(){

    return 0;
}