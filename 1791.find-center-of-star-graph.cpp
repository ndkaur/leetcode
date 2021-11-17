/*
 * @lc app=leetcode id=1791 lang=cpp
 *
 * [1791] Find Center of Star Graph
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
class Solution0 {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n= edges.size();
        int x= edges[0][0];
        int y =edges[0][1];
        if( edges[1][0]==x || edges[1][1]==x)
            return x;
        return y;
    }
};

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n= edges.size()+1;
        vector<int> input(n+1,0);
        int ans;
        for(auto edge:edges){ // counting 
            input[edge[0]]++;
            input[edge[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(input[i]==n-1) // checking count if repeating
                ans =i;
        }
        return ans;
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> edges={{1,2},{2,3},{4,2}};
    int ans = sol.findCenter(edges);
    cout<<ans;
   return 0;
}