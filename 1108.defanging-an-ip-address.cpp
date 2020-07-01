/*
 * @lc app=leetcode id=1108 lang=cpp
 *
 * [1108] Defanging an IP Address
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
    string defangIPaddr(string address) {
        return regex_replace(address,regex("\\."),"[.]");
    }
};
// @lc code=end


int main(){
    Solution sol;
    string address="255.75.869";
    string ans=sol.defangIPaddr(address);
    cout<<ans;

    return 0;
}