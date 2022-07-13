/*
 * @lc app=leetcode id=2099 lang=cpp
 *
 * [2099] Find Subsequence of Length K With the Largest Sum
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
//  kth largest num
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int n= nums.size();
        
        // O(nlogn)
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
            if(pq.size()>k)
                pq.pop();
        }
        // O(n)
        vector<pair<int,int>> ans;
        while(!pq.empty()){
            auto x= pq.top();
            pq.pop();
            ans.push_back({x.second, x.first}); // idx, ele
        }
        // O(k logk)
        sort(ans.begin(),ans.end());
        vector<int> result;
        // O(k)
        for(auto x:ans){
            result.push_back(x.second);
        }
        return result;
    }
};

//  put the {num, idx} in pq
// make ans of size k that has top k largest elemts {idx, ele}
//  sort the ans array on basis of idx 
//  final ans will be the elem in the ans array 
// @lc code=end


int main(){

    return 0;
}