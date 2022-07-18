/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
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
class Solution0{
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int len = trust.size();
        vector<int> ar1(n+1,0);
        vector<int> ar2(n+1,0);
        for(int i=0;i<len;i++){
            ar1[trust[i][0]]++; // count first index
            ar2[trust[i][1]]++; // count second index
        }
        int ans =0;
        for(int i=1;i<n+1;i++){ 
            if(ar1[i]==0) 
                ans =i; 
        }
        if(ar2[ans]== n-1) return ans;
        return -1;
    }
};

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int len = trust.size();
        vector<int> ar(n+1,0);
        for(int i=0;i<len;i++){
            ar[trust[i][0]]--; // outdegree
            ar[trust[i][1]]++; // indegree
        }
        for(int i=1;i<=n;i++){
            if(ar[i]==n-1) return i;
        }
        return -1;
    }
};

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
       vector<int> degree(n+1,0);
        for(int i=0;i<trust.size();i++){
            degree[trust[i][0]]--;
            degree[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++){
            //judge will have indegree of n-1 node 
            if(degree[i]==n-1)
                return i;
        }
        return -1;
    }
};
// @lc code=end

int main(){
    Solution sol;
    int n=2;
    vector<vector<int>> trust ={{1,2}};
    int ans = sol.findJudge(n,trust);
    cout<<ans;
    return 0;
}
