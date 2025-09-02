/*
 * @lc app=leetcode id=1329 lang=cpp
 *
 * [1329] Sort the Matrix Diagonally
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


class Solution0 {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        for(int j=0; j<m; j++){
            int i=0;
            int jj=j;
            vector<int> temp;
            vector<pair<int,int>> idx;

            idx.push_back({i,jj});
            temp.push_back(mat[i][jj]);

            while(mat[0][j] && i+1<n && jj+1<m){
                temp.push_back(mat[i+1][jj+1]);
                i= i+1;
                jj = jj+1;
                idx.push_back({i,jj});
            }
            sort(temp.begin(), temp.end());
            int p =0;
            for(auto id:idx){
                if(p<temp.size())
                    ans[id.first][id.second]= temp[p++];
            }
        }

        for(int i=0; i<n; i++){
            int j=0;
            int ii=i;
            vector<int> temp;
            vector<pair<int,int>> idx;

            idx.push_back({ii,j});
            temp.push_back(mat[ii][j]);

            while(mat[i][0] && ii+1<n && j+1<m){
                temp.push_back(mat[ii+1][j+1]);
                ii = ii+1;
                j = j+1;
                idx.push_back({ii,j});
            }
            sort(temp.begin(), temp.end());
            int p =0;
            for(auto id:idx){
                if(p<temp.size())
                    ans[id.first][id.second]= temp[p++];
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[i-j].push(mat[i][j]);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans[i][j] = mp[i-j].top();
                mp[i-j].pop();
            }
        }

        return ans;
    }
};


// @lc code=end



int main(){
    Solution sol;
    vector<vector<int>> mat={{3,3,1,1},{2,2,1,2},{1,1,1,2}};
    vector<vector<int>> ans =sol.diagonalSort(mat);
    for(auto x:ans)
        print(x);
    return 0;
}