/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
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

// heap sort(priority queue)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int num:nums){
            pq.push(num);
        }
        vector<int> ans;
        while(pq.size()){
            int t = pq.top();
            pq.pop();
            ans.push_back(t);
        }
        return ans;
    }
}; 

// @lc code=end


int main(){

    return 0;
}