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


class Solution {
public:
    vector<pair<int,int>> dirs ={{0,1},{1,0},{-1,0},{0,-1}};

    int findMaxGold(int row, int col, int& rows, int& cols, vector<vector<int>>& grid){
        if(row<0 || row>=rows || col<0 || col>=cols || grid[row][col]==0)
            return 0;

        int gold_present = grid[row][col];

        // marking the curr position as visited
        grid[row][col] = 0;

        int maxGold = 0;

        for(const auto& dir:dirs){
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            
            maxGold = max(maxGold, gold_present + findMaxGold(newRow, newCol, rows,cols, grid));
            
        }
        // in some case result might not be maximum 
        //  so we might need to traverse another path 
        //  so backtracking is required
        grid[row][col] = gold_present;
        return maxGold;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int number_of_rows = grid.size();
        int number_of_columns = grid[0].size();
        // 0 6 0
        // 5 8 7
        // 0 9 0
        int maxGold = 0;
        for(int row=0; row<number_of_rows; row++){
            for(int col=0; col<number_of_columns; col++){
                if(grid[row][col]!=0){
                    maxGold = max(maxGold, findMaxGold(row, col,number_of_rows, number_of_columns,grid));
                }
            }
        }
        return maxGold;
    }
};

// Time: O(k * 3 ^ k), where k is the number of cells with gold. We perform the analysis for k cells, and from each cell we can go in three directions.
// Memory: O(k) for the recursion.

class Solution {
public:
    vector<pair<int,int>> dirs ={{0,1},{1,0},{-1,0},{0,-1}};

    int findMaxGold(int row, int col, int& rows, int& cols, vector<vector<int>>& grid){
        int gold_present = grid[row][col];

        // marking the curr position as visited
        grid[row][col] = 0;

        int maxGold= 0;

        for( auto dir:dirs){
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            if(newRow>=0 && newRow<rows && newCol>=0 && newCol<cols && grid[newRow][newCol]!=0){
                maxGold = max(maxGold, findMaxGold(newRow, newCol, rows,cols, grid));
            }
        }
        // in some case result might not be maximum 
        //  so we might need to traverse another path 
        //  so backtracking is required
        grid[row][col] = gold_present;
        return maxGold + gold_present;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int number_of_rows = grid.size();
        int number_of_columns = grid[0].size();
        // 0 6 0
        // 5 8 7
        // 0 9 0
        int maxGold = 0;
        for(int row=0; row<number_of_rows; row++){
            for(int col=0; col<number_of_columns; col++){
                if(grid[row][col]!=0){
                    maxGold = max(maxGold, findMaxGold(row, col,number_of_rows, number_of_columns,grid));
                }
            }
        }
        return maxGold;
    }
};

int main(){

    return 0;
}