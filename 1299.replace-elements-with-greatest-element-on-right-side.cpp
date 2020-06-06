/*
 * @lc app=leetcode id=1299 lang=cpp
 *
 * [1299] Replace Elements with Greatest Element on Right Side
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
    vector<int> replaceElements(vector<int>& arr) {
        int len =arr.size();
        int mx = -1;
        vector<int> out(len);
        for(int i=len-1;i>=0;i--){
            out[i]=mx;
            mx=max(mx,arr[i]);
        }
        return out;
    } 
};
// @lc code=end
int main(){
    Solution sol;
    vi arr,output ;
    int i ,j;
    arr={17,18,5,4,6,1};
    output=sol.replaceElements(arr);
    print(output);
    return 0;
}