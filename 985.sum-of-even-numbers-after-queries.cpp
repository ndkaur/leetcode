/*
 * @lc app=leetcode id=985 lang=cpp
 *
 * [985] Sum of Even Numbers After Queries
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
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum=0;
        for(auto x:A){
            if(x%2==0) sum=sum+x;
        }
        int n=queries.size();
        vector<int> ans(n);
        for(int i=0;i<queries.size();i++){
            int val=queries[i][0];
            int idx=queries[i][1];
            if(A[idx]%2==0) sum=sum-A[idx];
            A[idx]=A[idx]+val;
            if(A[idx]%2==0)  sum=sum+A[idx];
            ans[i]=sum;
        }
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> queries={{1,0},{-3,1},{-4,0},{2,3}};
    vector<int> A={1,2,3,4};
    vector<int> ans=sol.sumEvenAfterQueries(A,queries);
    print(ans);
    return 0;
}