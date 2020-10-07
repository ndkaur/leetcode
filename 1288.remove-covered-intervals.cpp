/*
 * @lc app=leetcode id=1288 lang=cpp
 *
 * [1288] Remove Covered Intervals
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
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
bool compare(vector<int>&A,vector<int>&B){
		if(A[0]==B[0])
			return A[1]>B[1];
		return A[0]<B[0];
}

class Solution {
public:

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int count=0;
        int start=0;
        int end=1;
        while(end<intervals.size()){
            if(intervals[start][1] >= intervals[end][1]) 
                count++;
            else {
                start=end;
            }
            end++;
        }
        return intervals.size()-count;// remainig intervals is asked
    }
};
// @lc code=end



int main(){
    Solution sol;
    vector<vector<int>> intervals={{1,2},{1,4},{3,4}};
    int ans=sol.removeCoveredIntervals(intervals);
    cout<<ans;
    return 0;
}