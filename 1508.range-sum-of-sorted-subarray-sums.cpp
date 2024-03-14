/*
 * @lc app=leetcode id=1508 lang=cpp
 *
 * [1508] Range Sum of Sorted Subarray Sums
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

// o(n^2 log(n));
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subArray;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+= nums[j];
                subArray.push_back(sum);
            }
        }
        sort(subArray.begin(),subArray.end());
        long long mod= 1000000007;
        long long sum=0;
        for(int i=left-1;i<right;i++){
            sum = (sum+ subArray[i]) % mod;
        }
        return sum;
    }
}; 


// when we find sum of all subaary , while taking nums we pick in range of let to right 
// and that also in sorted manner 
// so pq will maintain that sorted order as its min heap 

class Solution { 
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i=0; i<n; i++){
            pq.push({nums[i], i+1}); // num , idx 
        }
        int sum = 0;
        int mod = 1e9+7;

        // left boundary is taken care by i 
        // right boundary is taken care by n

        for(int i=1; i<=right; i++){
            auto node = pq.top();
            pq.pop();

            if(i>=left) // i must lie in range [left, right]
                sum = (sum + node.first)%mod;
            
            if(node.second<n){ // if curr idx is less than the size of array 
                node.first += nums[node.second]; // calculate the prefix sum  = curr node val + next node val 
                node.second++; // increase the index 
                pq.push(node);
            }
        }
        return sum;
    }
};




// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,2,3,4};
    int n= 4;
    int left=1;
    int right=10;
    int ans= sol.rangeSum(nums,n,left,right);
    cout<<ans;
    return 0;
}