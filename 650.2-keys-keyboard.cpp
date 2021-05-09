/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
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
    int minSteps(int n) {
        if(n==1) return 0;
        if(n==2) return 2;
        int ans =0;
        int factor=2;
        while(n>1){
            while(n%factor==0){
                ans+=factor;
                n/=factor;
            }
            factor++;
        } 
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    int n =7;
    int ans=sol.minSteps(n);
    cout<<ans;
    return 0;
}