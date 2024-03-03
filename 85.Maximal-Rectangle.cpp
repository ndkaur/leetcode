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


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // area  = height * width
        // heights = [2,1,5,6,2,3]
        int n = heights.size();
        // next smaller elem ->monotonic inc stack
        stack<int> stk;
        vector<int> left(
            n, -1); // min towards the left of the number ->prev smaller
        vector<int> right(
            n, n); // min towards the right of the number->next smaller

        // dealing with the indexes for finding the width in between
        for (int i = 0; i < n; i++) {
            while (stk.size() && heights[stk.top()] > heights[i]) {
                right[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        while (stk.size()) {
            stk.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (stk.size() && heights[stk.top()] > heights[i]) {
                left[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            int height = heights[i];
            int widht = right[i] - left[i] - 1;
            ans = max(ans, height * widht);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int mx = 0;
        vector<int> dp(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    dp[j]++;
                else
                    dp[j] = 0;
            }
            int area = largestRectangleArea(dp);
            mx = max(mx, area);
        }
        return mx;
    }
};


int main(){

    return 0;
}