/*
 * @lc app=leetcode id=1266 lang=cpp
 *
 * [1266] Minimum Time Visiting All Points
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
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int len =points.size();
        int time=0;
        // using for loop and doing absolute subtraction  
        for(int i=0;i<len-1;i++){
            int x=abs(points[i][0]-points[i+1][0]);
            int y=abs(points[i][1]-points[i+1][1]);
            // taking the max value of abs subtract and adding it to time
            time = time+max(x,y);   
        }
        return time;
    }
};
// @lc code=end
int main(){
    Solution sol;
    vector<vi> points;
    int time;
    points={{1,1},{3,4},{-1,0}};
    time=sol.minTimeToVisitAllPoints(points);
    // print(time);
    cout<<time;
    return 0;
}