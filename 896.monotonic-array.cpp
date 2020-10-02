/*
 * @lc app=leetcode id=896 lang=cpp
 *
 * [896] Monotonic Array
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
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
    bool isMonotonic(vector<int>& A) {
        int n=A.size();
        bool inc =true ,dec=true;
        for(int i=0 ;i<n-1;i++){
            if(A[i]>A[i+1]) inc=false;
            if(A[i]<A[i+1]) dec=false;
            if(inc ==false && dec==false) return false;
        }
        return true;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<int> A={5,7,8,63,4};
    bool ans=sol.isMonotonic(A);
    cout<<ans;
    return 0;
}
