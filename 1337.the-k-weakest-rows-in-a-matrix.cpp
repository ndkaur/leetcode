/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
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
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k){
        vector<pair<int,int>> vone;
        vector<int> weakrow; 
        for(int i=0;i<mat.size();i++){
            int count=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1)
                    count++;
            }
            vone.push_back({count,i});
        }
        sort(vone.begin(),vone.end()); 
        
        for(int i=0;i<k;i++){
             weakrow.push_back(vone[i].second);
        }
        return weakrow;
    }
};

// binary search 
class Solution { //O(nlogm)
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int row= mat.size();
        int col= mat[0].size();
        vector<pair<int,int>> arr;
        for(int i=0;i<row;i++){
            int l=-1;
            int r=col;
            // int cnt=0;
            
            while(1+l<r){
                int mid= l+(r-l)/2;
                if(mat[i][mid]>0){
                    l=mid;
                }
                else
                    r= mid;
            }
            //  l will be at last 1
            // r will be at first 0
            arr.push_back({l+1,i});   
        }
        vector<int> ans;
        // for(auto [a,b]:arr){
        //     cout<<a<<" "<<b<<endl;
        // }
        sort(arr.begin(),arr.end());
        for(auto &it: arr){
            if(k==0)
                break;
            ans.push_back(it.second);
            k--;
        }
        return ans;
    }
};

// Priority queue 
//  inserting into pq + pop push + reversing the array 
// o(nlog n )+ O(logn)+ O(n)
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k){
        vector<int> ans;
        int row= mat.size();
        int col= mat[0].size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<row;i++){
            int cnt=0;
            for(int j=0;j<col;j++){
                if(mat[i][j]==1) 
                    cnt++;
            }
            //  stores cnt of each row with idx of row
            pq.push({cnt,i});
            //  we need smallest k elemts so pop the largest ones 
            if(pq.size()>k)
                pq.pop();
        }
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        //  ans will be in the max order so reverse 
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// {(1,0),(4,1),(1,2),(1,3)}  k=3 
//  (4,1) (1,2) (1,3)


// @lc code=end

int main(){
    Solution sol;
    vector<vector<int>>mat={{1,0,0,0},{1,1,1,1},{1,0,0,0},{1,0,0,0}}; 
    vector<int> weakrow;
    weakrow=sol.kWeakestRows(mat,3);
    print(weakrow);
    return 0;
}
