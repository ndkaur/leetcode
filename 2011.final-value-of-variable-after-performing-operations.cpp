/*
 * @lc app=leetcode id=2011 lang=cpp
 *
 * [2011] Final Value of Variable After Performing Operations
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
    int finalValueAfterOperations(vector<string>& op) {
        int n= op.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(op[i]== "--X" || op[i]== "X--")
                ans= ans-1;
            else 
                ans+= 1;
        }
        return ans;
    }
};
// @lc code=end


int main(){

    return 0;
}