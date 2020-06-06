/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
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
    int heightChecker(vector<int>& heights) {
        int len =heights.size();
        vector<int> order=heights;
        sort(order.begin(), order.end());
        int count =0;
        for(int i=0;i<len;i++){
            if(heights[i]!=order[i])
                count++;
        }
            return count;
        }
    };
int main(){
    Solution sol;
    vector<int> heights={1,1,4,2,1,3};
    int count;
    count=sol.heightChecker(heights);
    cout<<count;

    return 0;
}


// @lc code=end

