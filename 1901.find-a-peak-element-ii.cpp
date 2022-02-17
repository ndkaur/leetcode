/*
 * @lc app=leetcode id=1901 lang=cpp
 *
 * [1901] Find a Peak Element II
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

// find middle row
// find max element of that mid row-> then index of that max element
// mid row can be topmost , middle , bottom most 
// when middle -> if below elemt is greater that max ele -> move low
// else  move high 

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n= mat.size();
        int m= mat[0].size();
        
        int startRow=0;
        int endRow=n-1;
        while(startRow<=endRow){
            int midRow= startRow+(endRow-startRow)/2;
            //  index of max element of row 
            int rowMax = find(mat[midRow], mat[midRow].size());
            //  mid row is the top row
            if(midRow==0){
                if(mat[midRow][rowMax]> mat[midRow+1][rowMax])
                    return {midRow,rowMax};
            }
            // mid row is the last row
            if(midRow==n-1){
                if(mat[midRow][rowMax]> mat[midRow-1][rowMax])
                    return {midRow,rowMax};
            }
            // mid row is the mid row
            else if(midRow>0 && midRow< n){
                if(mat[midRow][rowMax] > mat[midRow+1][rowMax] && mat[midRow][rowMax]> mat[midRow-1][rowMax])
                    return {midRow,rowMax};
            }

            //  way of moving 
            if(mat[midRow][rowMax] < mat[midRow+1][rowMax]){
                startRow= midRow+1;
            }else 
                endRow= midRow-1;
        }
        return {-1,-1};
    }

    int find(vector<int> arr , int sz){ // finding the max element of row and then returning its index
        int mx= INT_MIN;
        int index=0;
        for(int i=0;i<sz;i++){
            if(arr[i]> mx){
                mx= arr[i];
                index=i;
            }
        }
        return index;
    }
};




// @lc code=end



int main(){
    Solution sol;
    vector<vector<int>> mat={{10,20,15},{21,30,14},{7,16,32}};
    vector<int> ans= sol.findPeakGrid(mat);
    print(ans);
    return 0;
}