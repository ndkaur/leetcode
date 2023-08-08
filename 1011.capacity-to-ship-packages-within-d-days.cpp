/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
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

class Solution {//O(N * log(sum(weights[]) – max(weights[]) + 1)) // indexex btwe the max sum and max weight
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int l = *max_element(weights.begin(), weights.end());
        int sum =0;
        for(int w:weights){
            sum+=w;
        }
        int ans;
        int r = sum;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(isPossible(weights, days, mid)){
                ans = mid;
                r = mid-1;
            }
            else
                l= mid+1;
        }
        return ans;
    }   
    bool isPossible(vector<int>& weights, int days, int currWeight){
        int n = weights.size();
        int total_weight =0;
        int cnt = 1;
        for(int i=0; i<n; i++){
            total_weight += weights[i];
            if(total_weight > currWeight){
                total_weight = weights[i];
                cnt++;
            }
        }
        return cnt<=days;
    }
};

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n= weights.size();
        int mx=0;
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            mx= max(weights[i],mx);
            sum+= weights[i];
        }
        int l= mx;
        int h= sum;
        //  we doing bsearch on the weights
        while(l<=h){
            int mid= l+(h-l)/2;
            if(isPossible(weights,days,mid)==true){ // if possible we become greedy and want to get a lesser value
                ans=mid;
                h=mid-1; // for lesser answer we reduce higher limit 
            }
            else 
                l= mid+1;
        }
        return ans;
    }
    bool isPossible(vector<int>& weights,int days,int mid){
        int d=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+= weights[i];
            if(sum>mid){ // if the sum is more than mid then we need one more day to complete the task
                d++;
                sum = weights[i]; // reset sum back at where i is
            }
        }
        if(d<=days)
            return true;
        return false;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> weights={1,2,3,4,5,6,7,8,9,10};
    int days=5;
    int ans = sol.shipWithinDays(weights,days);
    cout<<ans;
    return 0;
}