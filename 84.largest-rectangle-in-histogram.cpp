/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
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

class Solution0 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int mn = INT_MAX;
            int currArea  = 0;
            for(int j=i; j<n; j++){
                mn = min(mn, heights[j]);
                currArea = max(currArea, mn* (j-i+1));
            }
            ans= max(ans, currArea);
        }
        return ans;
    }
};


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        stack<int> stk;

        vector<int> prevse(n, -1);
        // montonic incr stak in reverse i
        for(int i=n-1; i>=0; i--){
            while(stk.size() && heights[stk.top()]>heights[i]){
                prevse[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        vector<int> nextse(n, n);
        // montonic inc stak with simple for loop
        for(int i=0; i<n; i++){
            while(stk.size() && heights[stk.top()]>heights[i]){
                nextse[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            int height = heights[i];
            int width = nextse[i]-prevse[i]-1;
            ans = max(ans, height*width);
        }
        return ans;
    }
};


// @lc code=end


int main(){

    return 0;
}