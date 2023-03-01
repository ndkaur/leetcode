/*
 * @lc app=leetcode id=427 lang=cpp
 *
 * [427] Construct Quad Tree
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
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* ConstructquadTree(vector<vector<int>>& grid, int rowStart, int rowEnd, int colStart, int colEnd){
        // out of bound condition
        if(rowStart > rowEnd || colStart > colEnd)
            return NULL;

        bool isLeaf = true;
        // give val the value of the grid so to compare the next 2 conditions
        // 1 . check if all vlaues of grid is same , all 1 or all 0
        // 2. check if its mix of 1 and 0 if so then apply  recursion 
        int val = grid[rowStart][colStart]; // taking first val in the grid

        for(int i=rowStart; i<=rowEnd; i++){
            for(int j= colStart; j<=colEnd; j++){
                if(grid[i][j] != val){ // different values in the grid
                    isLeaf = false;
                    break;
                }
            }
            if(!isLeaf)
                break;
        }
        if(isLeaf){
            // if its a leaf then give val of the box to the value
            return new Node(val, true);
        }

        // checking the sub box for recursion 
        int rowMid = (rowStart + rowEnd)/2;
        int colMid = (colStart + colEnd)/2;
        // row ->start , end   col -> start, end
        Node* topLeft = ConstructquadTree(grid, rowStart, rowMid, colStart, colMid);
        Node* topRight = ConstructquadTree(grid, rowStart, rowMid, colMid+1, colEnd);
        Node* bottomLeft = ConstructquadTree(grid,rowMid+1, rowEnd, colStart , colMid);
        Node* bottomRight = ConstructquadTree(grid,rowMid+1, rowEnd, colMid+1, colEnd);
        // returning the final answer in from of array 
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
        
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        // grid, rowStart , rowEnd , colStart , colEnd
        return ConstructquadTree(grid,0,n-1,0, n-1);
    }
    
};
Console

// @lc code=end


int main(){

    return 0;
}