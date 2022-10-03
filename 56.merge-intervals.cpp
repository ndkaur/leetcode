/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n<=1) return intervals;
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int j=0;

        for(int i=1; i<n; i++){
            // overlap prev end >= next start 
            if(ans[j][1] >= intervals[i][0]){
                // create a new interval only max will change 
                ans[j][1] = max(ans[j][1] , intervals[i][1]);
            }
            else { // not overlap move prev ahead 
                j++;
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
// @lc code=end


int main(){

    return 0;
}