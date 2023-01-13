/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution0 {
public:
    vector<vector<int>> generate(int numRows) {
        // numRows--;
        if(numRows==0)
            return {};
        vector<vector<int>> pascal(numRows ,vector<int>(numRows));
        pascal[0][0]=1;
        for(int i=1;i<numRows;i++){
            pascal[i][0]=pascal[i][i]=1;
            for(int j=1;j<numRows;j++){
                pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
            }
        }
        
        vector<vector<int>> ans(numRows);
        for(int row=0; row<numRows; ++row){
            for(int col=0; col<=row; ++col){
                ans[row].push_back(pascal[row][col]);
            }
        }
        
        return ans;
        
    }
};


class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            ans[i].resize(i+1);
            ans[i][0]= ans[i][i]=1;
            for(int j=1;j<i;j++){
                ans[i][j] = ans[i-1][j]+ans[i-1][j-1];
            }
        }
        return ans;
    }
};


vector<vector<int>> generate(int numRows) {
	vector<vector<int>> ret;
	for (int i = 0; i < numRows; i++) {
		vector<int> row(i + 1, 1);
		for (int j = 1; j < i; j++) {
			row[j] = ret[i - 1][j] + ret[i - 1][j - 1];
		}
		ret.push_back(row);
	}
	return ret;
}

// @lc code=end



int main(){
    Solution sol;
    int numRows=5;
    vector<vector<int>> pascal;
    pascal=sol.generate(numRows);
    for(auto x:pascal){
        print(x);
    }
    return 0;
}