/*
 * @lc app=leetcode id=1283 lang=cpp
 *
 * [1283] Find the Smallest Divisor Given a Threshold
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
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start

class Solution { // O(log(max(arr[]))*N),
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int  n= nums.size();
        int l = 1; // not possible 
        int r = *max_element(nums.begin(), nums.end());
        while(l<=r){
            int mid = l+(r-l)/2;
            if(isPossible(nums, threshold, mid)){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l; // polarity changed 
    }
    bool isPossible(vector<int>& nums, int thres, int val){
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += ceil((double)nums[i]/(double)val);
        }
        return (sum<=thres);
    }
};


class Solution0 {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        for(int d=1;d<=mx;d++){
            int sum = find_sum(nums,d);
            if(sum<=threshold) 
                return d;
        }
        return -1;
    }

    int find_sum(vi &nums, int d){
        int sum = 0;
        for(auto x: nums){
            int ans = (x + d-1)/d;
            sum+=ans;
        }
        return sum;
    }
};

//  ceil division = a+b-1 / b

class Solution1 {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=0;
        int r= *max_element(nums.begin(),nums.end())+1;
        int res=r;
        while(l+1<r){
            int mid = (l+(r-l)/2);
            int sum=0;
            for(auto x:nums){
                int ans = (x+ (mid-1))/mid;
                sum=sum+ans;
            }
            if(sum<=threshold){
                res=mid;
                r=mid;
            }
            else 
                l=mid;
        }
        return res;
    }
};

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n= nums.size();
        int l=1;
        int h= *max_element(nums.begin(),nums.end());
        int ans= -1;
        while(l<=h){
            int mid= l+(h-l)/2;
            if(possible(nums,threshold,mid)==true){
                h=mid-1;
                ans= mid;
            } else 
                l= mid+1;
        }
        return ans;
    }
    bool possible(vector<int>& nums,int threshold,int mid){
        int n= nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]%mid==0)
                count+= nums[i]/mid;
            else 
                count+= nums[i]/mid +1;
        }
        if(count>threshold)
            return false;
        return true;
    }
};

// @lc code=end


int main(){
    Solution sol; 
    vector<int> nums= {1,2,5,9}; 
    int th = 6; 
    int out;
    out = sol.smallestDivisor(nums,th); 
    deb(out);
    return 0;
}