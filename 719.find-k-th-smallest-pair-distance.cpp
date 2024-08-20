/*
 * @lc app=leetcode id=719 lang=cpp
 *
 * [719] Find K-th Smallest Pair Distance
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

class Solution0 {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // nlogn 
        priority_queue<int> pq; // logn

        for(int i=0; i<n; i++){ // n*n
            for(int j=i+1; j<n; j++){
                int val = nums[j]-nums[i];
                pq.push(val);
                if(pq.size()>k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};


class Solution {
public:
    bool check(int mid, vector<int>& nums, int& k){
        int n = nums.size();
        int cnt = 0;
        int j = 0;
        //{1  1  3}
        for(int i=0; i<n; i++){
            while(j<n && nums[j]-nums[i]<=mid){
                j++;
            }
            j--; 
            cnt += (j-i); // cnt is the no of pairs in between 
        }
        return (cnt>=k); // reduce the range 
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // nlogn 
        int l = 0;
        int r = nums[n-1]-nums[0];
        int ans = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(check(mid, nums, k)){
                r = mid-1;
                ans = mid; // consider it as answer as in next iteration we are trying to find some more smaller kth pair by reducing the range 
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={62,100,4};
    int k=2;
    int ans = sol.smallestDistancePair(nums,k);
    cout<<ans;
    return 0;
}