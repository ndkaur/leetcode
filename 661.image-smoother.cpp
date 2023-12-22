/*
 * @lc app=leetcode id=661 lang=cpp
 *
 * [661] Image Smoother
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
    // vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
    int smooth(vector<vector<int>>& img, int x, int y){
        int n = img.size();
        int m = img[0].size(); 
        int sum = 0;
        int cnt = 0;

        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                int nx = x+i;
                int ny = y+j;
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    sum += img[nx][ny];
                    cnt++;
                }
            }
        }
        return sum/cnt;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans[i][j] =  smooth(img, i, j);
            }
        }
        return ans;
    }
};
// @lc code=end


int main(){

    return 0;
}