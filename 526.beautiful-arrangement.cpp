/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}

// @lc code=start
class Solution {
public:
    int countArrangement(int n) {
        if(n==1) return 1;
        vector<bool> visited(n+1,false);
        int count=0;
        check(n,1,visited,count);
        return count;
    }
    void check(int n, int idx, vector<bool>&visited, int& count){
        if(idx>n) count++; // one case completed 
        for(int i=1;i<=n;i++){
            if(!visited[i] && (idx%i==0 || i%idx==0)){
                visited[i]=true;
                check(n, idx+1,visited,count);
                visited[i] = false;
            }
        }
    }
};
// @lc code=end


int main(){
    Solution sol;
    int n=2;
    int ans = sol.countArrangement(n);
    cout<<ans;
   return 0;
}