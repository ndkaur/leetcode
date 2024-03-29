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

// O(n log(n-k))
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       
        vector<int> result;
        
        if(k==nums.size()) return nums;
        
        unordered_map<int,int> count;
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


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        unordered_map<int,int> mp;
        for(auto num:nums)
            mp[num]++;
        for(auto itr:mp){
            pq.push({itr.second, itr.first});
            while(pq.size()>k)
                pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

//O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        // vvi array -> for each freq -> store the elemts with that freq 
        vector<vector<int>> store(n+1);
        for(auto itr:mp){
            int elm = itr.first;
            int freq= itr.second;
            store[freq].push_back(elm);
        }
        vector<int> ans;
        // we want max fre so start from right side
        for(int i=n; i>=0; i--){
            if(store[i].size()==0)
                continue;
            while(store[i].size()>0 && k>0){
                ans.push_back(store[i].back());
                store[i].pop_back();
                k--;
            }
        }
        return ans;
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