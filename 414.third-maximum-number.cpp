/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        set<int> s;
        for(auto x:nums){
            s.insert(x);
            if(s.size()>3)
                s.erase(s.begin());
        }
        if(s.size()==3)
           return *s.begin();
        else
            return *s.rbegin();
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> arr={2,1};
    int out=sol.thirdMax(arr);
    cout<<out;
    return 0;
}