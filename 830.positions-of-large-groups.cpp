/*
 * @lc app=leetcode id=830 lang=cpp
 *
 * [830] Positions of Large Groups
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int n=S.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            int count=1;
            int x=i; //to find the starting position of i
            while(S[i+1]==S[i]){
                i++;
                count++;
                if(i==n-1){
                    break;
                }
            }
            if(count>=3){
                ans.push_back({x,i});
            }
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<vector<int>> ans;
    string S= "abbbc";
    ans=sol.largeGroupPositions(S);
    for(auto x: ans){
        print(x);
    }
    return 0;
}