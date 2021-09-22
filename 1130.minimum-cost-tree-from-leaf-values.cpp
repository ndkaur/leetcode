/*
 * @lc app=leetcode id=1130 lang=cpp
 *
 * [1130] Minimum Cost Tree From Leaf Values
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
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

// class Solution { // gives wrong answer in some cases 
// public:
//     int mctFromLeafValues(vector<int>& arr) {
//         int n= arr.size();
//         int ans1=leftt(arr);
//         int ans2 = rightt(arr);
//         int ans= min(ans1,ans2);
//         return ans;
//     }
//     int leftt(vector<int>& arr){
//         int n =arr.size();
//         vector<int> dp;
//         int left = arr[0];
//         int right = arr[1];
//         int pro= left*right;
//         dp.push_back(pro);
//         for(int i=2;i<arr.size();i++){
//             left= max(left,right);
//             right = arr[i];
//             int product=left*right;
//             dp.push_back(product);
//         }
//         int sum1=0;
//         for(int i=0;i<dp.size();i++){
//             sum1+=dp[i];
//         }
//         return sum1;
//     }
//     int rightt(vector<int>& arr){
//         int n= arr.size();
//         vector<int> help;
//         int lft=arr[n-1];
//         int rht=arr[n-2];
//         int pro= lft*rht;
//         help.push_back(pro);
//         for(int i=n-3;i>=0;i--){
//             lft= max(lft,rht);
//             rht=arr[i];
//             int product=lft*rht;
//             help.push_back(product);
//         }
//         int sum2=0;
//         for(int i=0;i<help.size();i++){
//             sum2+=help[i];
//         }
//         return sum2;
//     }
// };


class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n= arr.size();
        vector<int> stk= {INT_MAX};
        int ans=0;
        for(auto x:arr){
            while(stk.size() && stk.back()<=x){
                int mid = stk.back();
                stk.pop_back();
                ans+= mid * min(stk.back(),x);
            }
            stk.push_back(x);
        }
        for(int i=2;i<stk.size();i++){
            ans+= stk[i]*stk[i-1];
        }
        return ans;
    }
};


// @lc code=end


int main(){
    Solution sol;
    // vector<int> arr ={15,13,5,3,15};
    vector<int> arr= {6,2,4};
    int ans= sol.mctFromLeafValues(arr);
    cout<<ans;
    return 0;
}