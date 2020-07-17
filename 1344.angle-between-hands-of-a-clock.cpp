/*
 * @lc app=leetcode id=1344 lang=cpp
 *
 * [1344] Angle Between Hands of a Clock
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

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    double angleClock(int hour, int minutes) {
        float h=(hour%12+ (float)minutes/60)*30;
        float m= minutes*6;
        float angle =abs(h-m);
        if(angle>180)
            angle=360-angle;
        return angle;
    }
};
// @lc code=end
int main(){
    Solution sol;
    int hour=12;
    int minutes=0;
    float angle=sol.angleClock(hour,minutes);
    cout<<angle;
    return 0;
}