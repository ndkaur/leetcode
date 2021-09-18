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

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        int row= m.size();
        int col = m[0].size();
        vector<int> ans;

        int up =0;
        int down = row-1;
        int left= 0;
        int right=col-1;
        int dir=0;
        while(up<=down && left<=right){
            if(dir==0){// left->right
                for(int i=left;i<=right;i++)
                    ans.push_back(m[up][i]);
                up++;
            }
            else if(dir==1){// up->down moving right not changing 
                for(int i=up;i<=down;i++)
                    ans.push_back(m[i][right]);
                right--;
            }
            else if(dir==2){ // right->left
                for(int i=right;i>=left;i--)
                    ans.push_back(m[down][i]);
                down--; // moving from right to left down not changing 
            }
            else if(dir==3){ // down ->top
                for(int i=down;i>=up;i--)
                    ans.push_back(m[i][left]);
                left++;
            }
            dir= (dir+1)%4;
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