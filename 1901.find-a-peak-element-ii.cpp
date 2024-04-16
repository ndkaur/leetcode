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


// 1st:- brute force:- for each idx check its all 4 dirs O(N*M*4)
// 2nd:- simply return the largest elem of matrix //O(N*M)

// 3rd:-  intuition:- perform binary search column wise 
// take mid of coulms and in that col pick the max elem , check its left and right element
// if its left elemts is greater than delte the right half cause its useless
// if right elme is greater then delete the left half 

// O(log M * N) ->logM cause binary search and N cause size of row 
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int l = 0;
        int h = m-1;

        while(l<=h){
            int mid = l+(h-l)/2;
            // max elemt of the col
            int mxRow = 0; // row in which max elemt of col is present 
            for(int i=0; i<n; i++){
                if(mat[mxRow][mid] <= mat[i][mid])
                    mxRow = i;
            }

            // now check left and right side of the max elem from the curr col
            // check left 
            bool leftBig = false;
            if(mid-1>=0 && mat[mxRow][mid-1] > mat[mxRow][mid]){
                leftBig = true;
            }
            
            bool rightBig = false;
            if(mid+1<m && mat[mxRow][mid] < mat[mxRow][mid+1]){
                rightBig = true;
            }

            // when mid is itself the most greater then its the peak
            if(leftBig==false && rightBig==false)
                return {mxRow, mid};
            else if(leftBig){ // left side elem is greater then mid then right side is of no use 
                h = mid-1;
            }
            else 
                l = mid+1;
        }
        return {-1,-1};
    }
};


class Solution { //n*logm
public:
    int findMx(vector<vector<int>>& mat, int n, int m, int mid){
        // find mx in the curr full col 
        int mxVal = -1;
        int idx = -1;
        for(int i=0; i<n; i++){
            if(mat[i][mid]>mxVal){
                mxVal = mat[i][mid];
                idx = i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int l = 0;
        int r = m-1;
        while(l<=r){
            int mid = l + (r-l)/2; // col idx 
            // we are traversing col wise check 
            int mxRowidx =  findMx(mat,n, m, mid); // row idx 
            // mid-1, mid, mid+1
            int left = mid-1>=0 ? mat[mxRowidx][mid-1] : -1;
            int right = mid+1<m ? mat[mxRowidx][mid+1] : -1;

            if(left < mat[mxRowidx][mid] && mat[mxRowidx][mid]>right)
                return {mxRowidx, mid};
            else if(mat[mxRowidx][mid]<left){
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        } 
        return {-1,-1};
    }
};

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