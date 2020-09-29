/*
 * @lc app=leetcode id=888 lang=cpp
 *
 * [888] Fair Candy Swap
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
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        set<int> s;
        for(auto x:A) s.insert(x);

        int suma=accumulate(A.begin(),A.end(),0);
        int sumb=accumulate(B.begin(),B.end(),0);
        int diff= (sumb-suma)/2;

        for(auto x:B){
            int req= x-diff;
            if(s.count(req))
                return {req,x};
        }
        return{-1,-1};
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> A={1,1};
    vector<int> B={2,2};
    vector<int> ans=sol.fairCandySwap(A,B);
    print(ans);
    return 0;
}