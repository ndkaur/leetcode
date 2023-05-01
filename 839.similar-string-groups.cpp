/*
 * @lc app=leetcode id=839 lang=cpp
 *
 * [839] Similar String Groups
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

// time -> O(n^2 + m)
// space ->O(n+m)
class Solution {
public:
    int numSimilarGroups(vector<string>& strs){
        int n = strs.size();
        int cnt =0;
        vector<bool> visited(n,0);
        for(int i=0; i<n; i++){
            if(visited[i]==1)
                continue;
            cnt++;
            dfs(i,strs,visited);
        }
        return cnt;
    }
    void dfs(int i, vector<string>& strs, vector<bool>& visited){
        visited[i] = 1;
        for(int j=0; j<strs.size(); j++){
            if(visited[j])
                continue;
            if(is_similar(strs[i],strs[j]))
                dfs(j,strs,visited);
        }
    }

    bool is_similar(string a, string b){
        int cnt=0;
        for(int i=0; i<a.size(); i++){
            if(a[i]!=b[i])
                cnt++;
        }
        return (cnt==2 || cnt==0);
    }
};

// @lc code=end


int main(){

    return 0;
}