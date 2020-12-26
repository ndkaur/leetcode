/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Friend Circles
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
    int n;
    unordered_map<int,int> visited;
public:
    int findCircleNum(vector<vector<int>>& matrix) {
        n= matrix.size();
        visited.clear();
        int ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                friend_circle(i,matrix);
            }
        }
        return ans;
    }
    void friend_circle(int x, vector<vector<int>>& matrix){
        visited[x]=1; // marking it visited
        for(int j=0;j<n;j++){ 
            if(matrix[x][j] && !visited[j]){
                friend_circle(j,matrix);
            }
        }
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> matrix={{1,1,0},{1,1,0},{0,0,1}};
    int ans= sol.findCircleNum(matrix);
    cout<<ans;
    return 0;
}