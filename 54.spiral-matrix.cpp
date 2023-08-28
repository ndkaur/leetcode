/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
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
class Solution0 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.empty() || matrix.size()==0)
            return ans;
        int n =matrix.size();// horizontal
        int m =matrix[0].size();// verticals 
        int up=0;
        int down = n-1;
        int left= 0;
        int right = m-1;
        while(ans.size()<n*m){
            for(int j=left;j<=right && ans.size()<n*m;j++)
                ans.push_back(matrix[up][j]);
            for(int i=up+1;i<=down-1 && ans.size()<n*m;i++)
                ans.push_back(matrix[i][right]);
            for(int j=right; j>=left && ans.size()<n*m;j--)
                ans.push_back(matrix[down][j]);
            for(int i=down-1;i>=up+1 && ans.size()<n*m;i--)
                ans.push_back(matrix[i][left]);
            left++;
            right--;
            up++;
            down--;
        }
        return ans;
    }
};

class Solution { //O(N*M)
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
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
                    // row remains constant and row = up
                    ans.push_back(matrix[up][i]);
                }
                up++; // update up for next iteration
            }
            // moving from up to down
            else if(dir==1){ 
                for(int i=up; i<=down; i++){
                    // col remains constant and col = right
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            // moving from right to left
            else if(dir==2){
                for(int i=right; i>=left; i--){
                    // row remains constant row=down
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }
            // moving from down to up
            else if(dir==3){
                for(int i=down; i>=up; i--){
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

// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans=sol.spiralOrder(matrix);
    print(ans);
    return 0;
}

    // l     r 
// t-> 1, 2, 3
    // 4, 5, 6
// d-> 7, 8, 9