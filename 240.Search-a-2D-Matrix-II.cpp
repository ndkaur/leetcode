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


// brute force:- iterate all elmts and check if target //O(N*M)


// better approach 
// taking each row and applying bs on it 

class Solution { //O(N*logM), 
public:
    bool binarySearch(vector<int>& nums, int target){
        int n = nums.size();
        int l = 0;
        int h = n-1;
        while(l<=h){
            int mid = l +(h-l)/2;
            if(nums[mid]==target)
                return true;
            else if(nums[mid]>target)
                h = mid-1;
            else 
                l = mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            bool flag = binarySearch(matrix[i], target);
            if(flag)
                return true;
        }
        return false;
    }
};

// optimal approach 
class Solution { // O(N+M)
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0;
        int col = m-1;
        // ------->    matrix is increasing in this form 
        //        |
        //        |
        //        V
        while(row<n && col>=0){
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]<target){
                // its sure that target is greater than the last elem of the curr row
                // so the row is in increaing order then find target in next row               
                row++; 
            }
            else 
                col--;
        }
        return false;
    }
};



int main(){

    return 0;
}