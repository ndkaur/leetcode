/*
 * @lc app=leetcode id=1460 lang=cpp
 *
 * [1460] Make Two Arrays Equal by Reversing Sub-arrays
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
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
       sort(arr.begin(),arr.end());
        sort(target.begin(),target.end());
        if(target==arr) return true;
        return false;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<int> target= {1,2,3,4};
    vector<int> arr={2,4,1,3};
    bool ans= sol.canBeEqual(target,arr);
    cout<<ans;
    return 0;
}
