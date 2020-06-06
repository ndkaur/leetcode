/*
 * @lc app=leetcode id=1304 lang=cpp
 *
 * [1304] Find N Unique Integers Sum up to Zero
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
    vector<int> sumZero(int n) {
        vector<int> output;
        int sum =0;
        for(int i=0;i<n-1;i++){
            sum=sum +i;
            output.push_back(i);
        }
        output.push_back(-sum);
        return output;
    }
};
// @lc code=end
int main(){
    Solution sol;
    int sum,n;
    vi output;
    output=sol.sumZero(10);
    print(output);
    return 0;
}