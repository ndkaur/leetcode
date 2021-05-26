/*
 * @lc app=leetcode id=873 lang=cpp
 *
 * [873] Length of Longest Fibonacci Subsequence
 */
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

// @lc code=start
class Solution0 {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> s(arr.begin(),arr.end());
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x = arr[j];
                int y= arr[i]+arr[j];
                int len= 2;
                while(s.find(y) != s.end()){
                    int z= x+y;
                    x=y;
                    y=z; 
                    len++;
                    ans = max(ans,len);
                }
            }
        }
        return ans>=3 ? ans:0; 
    }
};

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int ans =0;
        unordered_map<int,int> idx;
        for(int i=0;i<n;i++)    
            idx[arr[i]]=i;
        unordered_map <int,int> longest;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]-arr[j]<arr[j] && idx.count(arr[i]-arr[j])){
                    int k = idx[arr[i]] -arr[j];
                    longest[j*n+i] = longest[i*n+j]+1;
                    ans = max(ans,longest[j*n+i]+2);
                }
            }
        }
        return ans >=3 ? ans :0;
    }
};


// @lc code=end


int main(){
    Solution sol;
    vector<int> arr= {1,3,7,11,12,14,18};
    int ans = sol.lenLongestFibSubseq(arr);
    cout<<ans;
    return 0;
}