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
        while(l<=h){
            int mid= l+(h-l)/2;
            if(isPossible(weights,days,mid)==true){
                ans=mid;
                h=mid-1;
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
            if(sum>mid){
                d++;
                sum = weights[i];
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