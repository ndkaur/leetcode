/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
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
    int singleNumber(vector<int>& nums) {
        int n= nums.size();
        map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        for(auto itr:mp){
            if(itr.second==1)
                return itr.first;
        }
        return 0;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n= nums.size();
        int ans=0;
        for(int num:nums){
            ans = ans ^ num;
        }
        return ans;
    }
};




// @lc code=end


int main(){

    return 0;
}