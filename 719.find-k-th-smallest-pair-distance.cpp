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


class Solution { // smae like agresive cows
public:
    int check(vector<int>& nums, int k, int mid){
        int n = nums.size();
        int cnt =0;
        // cnt of distances that are less than mid
        int s=0;
        int e = 0;
        while(e<n){
            while(nums[e]-nums[s]>mid && s<n){
                s++;
            }
            // now dist less than mid
            cnt += e-s;
            e++;
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n  = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0;  // not possible 
        int h = nums[n-1]-nums[0];
        while(l<=h){
            int mid = l+(h-l)/2;
            int dist = check(nums, k, mid);
            if(dist<k){
                l = mid+1;
            }
            else 
                h = mid-1;
        }
        return l;
    }
};


class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        int l=0;
        int h= nums[n-1]-nums[0];
        while(l<h){
            int mid= l+(h-l)/2;
            int count=possible(nums,k,mid);
            if(count<k){
                l=mid+1;
            }else 
                h=mid;
        }
        return l;
    }
    int possible(vector<int>& nums, int k,int mid){
        int n= nums.size();
        int count=0;
        int i=0; // checking how many nos are smaller than mid
        // but to count the nos from starting till mid which are less than or equal to mid 
        // we increment our i till nums are greater than mid
        for(int j=1;j<n;j++){
            while(nums[j]-nums[i]>mid)
                i++;
            count+= j-i;
        }
        return count;
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