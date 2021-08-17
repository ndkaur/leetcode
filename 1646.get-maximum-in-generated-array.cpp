/*
 * @lc app=leetcode id=1646 lang=cpp
 *
 * [1646] Get Maximum in Generated Array
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0 ||n==1) return n;
        vector<int> nums(n+1);
        nums[0]=0;
        nums[1]=1;
        int mx=1;
        for(int i=2;i<=n;i++){
            nums[i]= (i%2==0) ? nums[i/2]: nums[i/2]+nums[i/2+1];
            mx= max(mx,nums[i]);
        }
        return mx;
    }
};
// @lc code=end


int main(){
    Solution sol;
    int n=7;
    int ans =sol.getMaximumGenerated(n);
    cout<<ans;
    return 0;
}