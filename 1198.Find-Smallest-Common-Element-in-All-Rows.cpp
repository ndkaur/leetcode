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


// brute force count -> store cnt , whose cnt==n is the ans

// binary search -> O(nlogn)
class Solution {
public:
    bool find(vector<int>& arr, int target){
        int l = 0;
        int r = arr.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(arr[mid]==target)
                return true;
            else if(arr[mid]<target){
                l = mid+1;
            }
            else 
                r = mid-1;
        }
        return false;
    }
    int smallestCommonElement(vector<vector<int>>& mat) {
        int n = mat.size();
        if(n==1)
            return mat[0][0];
        // make each num of row 0 as target and check in each other remainig row
        for(auto num:mat[0]){
            int cnt = 0;
            for(int i=1; i<n; i++){
                if(find(mat[i], num)){
                    cnt++;
                }
                else 
                    break;
            }
            if(cnt==n-1) // already exisiting in 0th row 
                return num;
        }
        return -1;
    }
};

// [1,2,3,4,5]
// [2,4,5,8,10]
// [3,5,7,9,11]
// [1,3,5,7,9]


int main(){

    return 0;
}