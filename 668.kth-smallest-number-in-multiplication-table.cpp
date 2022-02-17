/*
 * @lc app=leetcode id=668 lang=cpp
 *
 * [668] Kth Smallest Number in Multiplication Table
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
class Solution0 { // o(m*n) + o(m*n(log(m*)))
public:
    int findKthNumber(int m, int n, int k) {
        vector<int> matrix(m*n);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                matrix[(i-1)*n+ j-1] = i*j;
            }
        }
        sort(matrix.begin(),matrix.end());
        return matrix[k-1];
    }
};// time limit exceeded 

class Solution {  // o nlog n
public:
    int findKthNumber(int m, int n, int k) {
        int l=1;
        int h=m*n;
        while(l<=h){
            int mid= l+(h-l)/2;
            int capacity= possible(m,n,k,mid);
            if(capacity<k){
                l=mid+1;
            } else 
                h=mid-1;
        }
        return l;
    }
    int possible(int m , int n, int k, int mid){
        int count=0; // count of elements less than mid in each row
        for(int i=1;i<=m;i++){
            count+=min(n,mid/i);
        }
        return count;
    }
};

// @lc code=end


int main(){
    Solution sol;
    int m=3;
    int n=3;
    int k=5;
    int ans = sol.findKthNumber(m,n,k);
    cout<<ans;
    return 0;
}