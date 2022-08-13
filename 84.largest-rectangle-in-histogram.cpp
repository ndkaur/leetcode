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

// formula -> min height * ( heights in between )
// heights in between  ->  right - left +1

class Solution { //O(N^2)
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        int mx=0;
        for(int i=0;i<n;i++){
            int cur=0;
            int mnheight= INT_MAX;
            for(int j=i;j<n;j++){
                mnheight = min(mnheight , heights[j]);
                cur= max(cur, mnheight * (j-i+1));
            }
            mx= max(mx, cur);
        }
        return mx;
    }
};


// here it a increasing monotonic stack  as we want min heigth ,, so we find the next smaller ele
// so ans = min height * (no of rectangles in between )
// no of rectangles in between -> i- nxt min top value on stk -1 

class Solution {  //O(N)
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int ans=0;
        stack<int> stk;
        heights.push_back(0);
        for(int i=0;i<heights.size();i++){
            while(!stk.empty() && heights[stk.top()] > heights[i]) {// decresing order 
                int top = heights[stk.top()]; // curr height
                stk.pop();
                int nxt = stk.empty() ? -1 : stk.top(); // nxt height in stk at stk top
                ans = max(ans, top * (i-nxt-1));
            }
            stk.push(i);
        }
        return ans;
    }
};


// (right smaller idx - left smaller idx +1) * a[i]
// using two stcks 

class Solution {   // o(N) +O(N)
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        stack<int> stk;
        vector<int> left(n);
        vector<int> right(n);

        for(int i=0;i<n;i++){
            while(!stk.empty() && heights[stk.top()] >= heights[i]){
                stk.pop();
            }
            if(stk.empty())
                left[i]=0;
            else 
                left[i] = stk.top() + 1 ; // idx 
            stk.push(i);
        }

        // clar the stack for reuse 
        while(!stk.empty()) 
            stk.pop();
        
        // right array 
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && heights[stk.top()] >=  heights[i]){
                stk.pop();
            }
            if(stk.empty())
                right[i] = n-1;
            else 
                right[i] = stk.top() -1; // 0 base idxing 
            stk.push(i);
        }

        // (left- right +1) * height[i]
        int ans =0;
        for(int i=0;i<n;i++){
            ans = max(ans, heights[i] * (right[i] - left[i] + 1));
        }
        return ans;
    }
};







// @lc code=end


int main(){

    return 0;
}