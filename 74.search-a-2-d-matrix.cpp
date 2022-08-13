/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
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
class Solution { //O(logn + logm)
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n= matrix.size();
        int m= matrix[0].size();
        if(!n) return 0;
        if(!m) return 0;
        int l=0,r=m*n-1;

        while(l<=r){
            int mid=l+(l-r)/2;
            if(matrix[mid/m][mid%m] ==target) return true;
            if(matrix[mid/m][mid%m] <target)
                l=mid+1;
            else 
                r=mid-1;
        }
        return false;
    }
};


class Solution { //O(N^2)+ O(nlogn)
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n= matrix.size();
        vector<int> arr;
        for(int i=0;i<n;i++){
            for(int j=0;j<matrix[0].size();j++){
                arr.push_back(matrix[i][j]);
            }
        }
        int l=-1;
        int r= arr.size();
        while(1+l<r){
            int mid = l+(r-l)/2;
            if(arr[mid]== target)
                return true;
            else if (arr[mid]<target)
                l= mid;
            else 
                r= mid;
        }
        return false;
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> matrix = {{}};
    int target=300;
    bool ans =sol.searchMatrix(matrix,target);
    cout<<ans;
    return 0;
}