/*
 * @lc app=leetcode id=967 lang=cpp
 *
 * [967] Numbers With Same Consecutive Differences
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
    vector<int> numsSameConsecDiff(int n, int k){
        vector<int> curr={0,1,2,3,4,5,6,7,8,9};
        for(int i=2;i<=n;i++){
            vector<int> curr2;
            for(int x:curr){ // int req = y+i=k //y=i-k , y=i+k
                int y= x%10;
                if(x>0 && y+k<10)
                    curr2.push_back(x*10+y+k); // when no is smaller than k 
                if(x>0 && k>0 && y-k>=0) 
                    curr2.push_back(x*10+y-k); // when no is greater than k 8>7
            }
            curr=curr2;
        }
        return curr;
    }
};
// @lc code=end


int main(){
    Solution sol;
    int n=2;
    int k=1;
    vector<int> ans=sol.numsSameConsecDiff(n,k);
    print(ans);
    return 0;
}