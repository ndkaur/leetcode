#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
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

class Solution0 { // brute force 
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n= matrix.size();
        int m=matrix[0].size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans.push_back(matrix[i][j]);
            }
        }
        sort(ans.begin(),ans.end());
        int a=0;
        for(int i=0;i<ans.size();i++){
            if(i==k-1)
                a= ans[i];
        }
        return a;
    }
}; // o(n^2 log(n))

class Solution1 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++)
                pq.push(matrix[i][j]);
        }
        while(pq.size()!=k){
            pq.pop();
        }
        return pq.top();
    } 
};

class Solution {  // binary search 
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n= matrix.size();
        int l= matrix[0][0];
        int h= matrix[n-1][n-1];
        while(l<h){
            int mid = l+(h-l)/2;
            int indexOfMid = rank(matrix,mid);
            if(indexOfMid < k)
                l= mid+1;
            else 
                h= mid;
        }
        return l;
    }
    int rank(vector<vector<int>>& matrix,int target){
        int n= matrix.size();
        int i= n-1;
        int j=0;
        int count=0;
        while(i>=0 && j<n){
            // target = mid
            if(target<matrix[i][j])
                i--;
            else {
                j++;
                count = count+i+1;
            }
        }
        return count;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix={{1,5,9},{10,11,13},{12,3,15}};
    int k=8;
    int ans = sol.kthSmallest(matrix,k);
    cout<<ans;
    return 0;
}