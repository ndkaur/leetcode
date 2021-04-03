/*
 * @lc app=leetcode id=1025 lang=cpp
 *
 * [1025] Divisor Game
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
    bool divisorGame(int N) {
        if(N%2==0)
            return true;
        else 
            return false;
    }
};
// @lc code=end


int main(){
    Solution sol;
    int n=3;
    bool ans=sol.divisorGame(n);
    cout<<ans;
    return 0;
}