/*
 * @lc app=leetcode id=1980 lang=cpp
 *
 * [1980] Find Unique Binary String
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

// greedy 
class Solution0 {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        int sz = nums.size();
        string ans = "";
        for(int i=0; i<sz; i++){
            ans += nums[i][i]=='0' ? '1' : '0';
        }
        return ans;
        // "111","011","001" 
        // new ans[0] = nums[0][0] = 1 so 0
        //  ans[1] = nums[1][1] = 1 so 0
        //  ans[2] = nums[2][2] = 1 so  0
        // ans = 000
    }
};

// backtracking 
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        int sz = nums[0].size();
        string ans(sz, '0');
        unordered_set<string> st(nums.begin(), nums.end());
        return dfs(0, ans, st);
    }
    string dfs(int i, string& ans, unordered_set<string>& st){
        if(st.find(ans)==st.end())
            return ans;
        ans[i]='1';
        return dfs(i+1, ans, st);
        ans[i]='0';
        return dfs(i+1, ans, st);
    }
};

//  7 , 3, 1  -> 1->7

// 0
// 1
// 10   2
// 11   3
// 100  4 
// 101  5
// 110  6
// 111  7
// 1000 8
// 1001 9

// @lc code=end


int main(){

    return 0;
}