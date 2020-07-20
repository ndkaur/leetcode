/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
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

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}
// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       
        vector<int> result;
        
        if(k==nums.size()) return nums;
        
        map<int,int> count;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto i:count){
            pq.push({i.second,i.first}); 
        }

        for(int i=0;i<k;i++){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
// @lc code=end



int main(){
    Solution sol;
    vector<int> nums={-1,-1};
    int k=1;
    vector<int> result =sol.topKFrequent(nums,k);
    print(result);
    return 0;
}