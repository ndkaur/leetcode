/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
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



class Solution1 { //O(N*N)
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            int pro = 1;
            for(int j=0; j<n; j++){
                if(i==j) continue;
                pro = pro  * nums[j];
            }
            ans.push_back(pro);
        }
        return ans;
    }
};


class Solution0 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> pre(n);
        pre[0]=1;
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1]*nums[i-1];
        }
        vector<int> suf(n);
        suf[n-1]=1;
        for(int i=n-2; i>=0; i--){
            suf[i] = suf[i+1]*nums[i+1];
        }

        for(int i=0; i<n; i++){
            ans[i] = pre[i]*suf[i];
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        int cur = 1;
        for(int i=0; i<n; i++){
            ans[i] = ans[i]*cur;
            cur = cur*nums[i];
        }
        cur =1;
        for(int i=n-1; i>=0; i--){
            ans[i] = ans[i]*cur;
            cur = cur*nums[i];
        }
        return ans;
    }
};




// @lc code=end



int main(){

    return 0;
}