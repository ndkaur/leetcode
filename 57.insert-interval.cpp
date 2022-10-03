/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newin) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int m = newin.size();
        for(int i=0; i<n; i++){
            // non overlaping before the new interval 
            //{1,2}  {4,8}  2<4
            if(intervals[i][1] < newin[0]){
                ans.push_back(intervals[i]);
            }
            // non overlaping after the new interval 
            // {12, 16}  {4 ,8}  12>8
            else if(intervals[i][0] > newin[1]){
                ans.push_back(newin);
                newin = intervals[i];
            }
            // overlap of intervals
            else if(intervals[i][1] >= newin[0] || intervals[i][0] <= newin[1]){
                newin[0] = min(intervals[i][0] , newin[0]);
                newin[1] = max(newin[1], intervals[i][1]);
            }
        }
        ans.push_back(newin);
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newin) {
        int n = intervals.size();
        int i=0;
        vector<vector<int>> ans;
        // before new interval 1,2   4,8   2<4 end of cur < start of new 
        while(i<n && intervals[i][1] < newin[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        // overlap of intervals  3,5  4,8    3<8   start of cur < end of new 
        while(i<n && intervals[i][0] <= newin[1]){
            newin[0] = min(newin[0], intervals[i][0]);
            newin[1] = max(newin[1], intervals[i][1]);
            i++;
        }
        // now the new interval is formed 
        ans.push_back(newin);
        // after the new interval  12,16  4,8    start of cur > end of new 
        while(i<n){ // all the remaining 
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newin = {2,5};
    vector<vector<int>> ans= sol.insert(intervals, newin);
    for(auto a:ans){
        for(auto i:a){
            cout<<i<<endl;
        }
        cout<<endl;
    }
    return 0;
}