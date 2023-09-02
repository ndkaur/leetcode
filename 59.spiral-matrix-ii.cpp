/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        spiralOrder(1,ans);
        return ans;
    }

    vector<int> spiralOrder(int val, vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        // pointers of dirs
        int left = 0;
        int right = col-1; // to reach right we travelled cols
        int up = 0;
        int down = row-1; // to reach down we travled rows

        vector<int> ans;
        int dir = 0;
        // 0 = left->right 
        // 1 = up -> down 
        // 2 = right->left
        // 3 = down->up 

        while(left<=right && up<=down){
            // moving from left to right
            if(dir==0){ 
                for(int i=left; i<=right; i++){
                    matrix[up][i] = val;
                    val++;
                    // row remains constant and row = up
                    ans.push_back(matrix[up][i]);
                }
                up++; // update up for next iteration
            }
            // moving from up to down
            else if(dir==1){ 
                for(int i=up; i<=down; i++){
                    matrix[i][right] = val;
                    val++;
                    // col remains constant and col = right
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            // moving from right to left
            else if(dir==2){
                for(int i=right; i>=left; i--){
                    matrix[down][i] = val;
                    val++;
                    // row remains constant row=down
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }
            // moving from down to up
            else if(dir==3){
                for(int i=down; i>=up; i--){
                    matrix[i][left] = val;
                    val++;
                    // col remians constant col = left
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            // change the dir 
            dir  = (dir+1)%4;
        }
        return ans;
    }
};


class Solution0 {
    const vector<vector<int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
public:
    vector<vector<int>> generateMatrix(int n) {
        int val=1;
        int x=0;
        int y=0;
        // size of ans is n 
        vector<vector<int>> ans(n, vector<int>(n));
        ans[x][y]= val; // initilizing first val as 1
        val++;
        vector<int> currDir=dirs[0]; // going in direction{0,1}

        while(val<=n*n){
            x=x+currDir[0]; // current direction is (0,1) x=0
            y=y+currDir[1]; // y=1
            // !ans[x][y] means no already existing val at that position
            while(x>=0 && x<n && y>=0 && y<n && !ans[x][y]){
                ans[x][y]=val;
                val++;
                x=x+currDir[0];
                y=y+currDir[1];               
            }
            // if we get out of the grid 
            x=x-currDir[0];
            y=y-currDir[1];//we get back in grid
            // to find the next direction to go in 
            for(auto dir:dirs){
                int newx=x+dir[0];
                int newy=y+dir[1];
                if(newx>=0 && newx<n && newy>=0 && newy<n && !ans[newx][newy]){
                    currDir = dir;
                    break;
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int top=0;
        int bottom = n-1;
        int left= 0;
        int right=n-1;
        int val=1;
        while(left<=right && top<=bottom){ 
            for(int i=left;i<=right;i++)// left->right
                ans[top][i]=val++;
            top++;
            for(int i=top;i<=bottom;i++)// top->bottom
                ans[i][right] =val++;
            right--;
            for(int i=right;i>=left;i--) // right->left
                ans[bottom][i]=val++;
            bottom--;
            for(int i=bottom;i>=top;i--) // bottom->top
                ans[i][left]= val++;
            left++;
        }
        return ans;
    }
};


// @lc code=end


int main(){
    Solution sol;
    int n=4;
    vector<vector<int>> ans=sol.generateMatrix(n);
    for(auto x:ans){
        print(x);
    }
    return 0;
}