/*
 * @lc app=leetcode id=1748 lang=cpp
 *
 * [1748] Sum of Unique Elements
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
    int sumOfUnique(vector<int>& nums) {
        map<int,int>mp;
        for(auto n:nums)
            mp[n]++;
        int sum=0;
        for(auto& it:mp){
            if(it.second==1)
                sum+=it.first;
        }
        return sum;
    }
};
// @lc code=end


int main(){

    return 0;
}