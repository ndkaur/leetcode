/*
 * @lc app=leetcode id=885 lang=cpp
 *
 * [885] Spiral Matrix III
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

//  x= row start
// y= col start

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int row, int col, int x, int y) {
        vector<vector<int>> ans;
        int n=0;
        int steps=1;
        while(n<row*col){
            for(int i=0;i<steps;i++){
                if(x>=0 && y>=0 && x<row && y<col){
                    ans.push_back(vector<int>{x,y});
                    n++;
                }
                y++; // start col++
            }
            for(int i=0;i<steps ;i++){
                if(x>=0 && y>=0 && x<row && y<col){
                    ans.push_back(vector<int>{x,y});
                    n++;
                }
                x++; // start row++
            }
            steps++;
            for(int i=0;i<steps;i++){
                if(x>=0 && y>=0 && x<row && y<col){
                    ans.push_back(vector<int>{x,y});
                    n++;
                }
                y--;
            }
            for(int i=0;i<steps;i++){
                if(x>=0 && y>=0 && x<row && y<col){
                    ans.push_back(vector<int>{x,y});
                    n++;
                }
                x--;
            }
            steps++;
        }
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    int rows=5;
    int cols=6;
    int rstart=1;
    int cstart=4;
    vector<vector<int>> ans = sol.spiralMatrixIII(rows,cols,rstart,cstart);
    for(auto n:ans){
        print(n);
    }
   return 0;
}