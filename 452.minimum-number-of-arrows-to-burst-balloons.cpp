/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
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

class Solution {
public:
    static bool comp(vector<int>& a , vector<int>& b){
        return a[1] < b[1]; // increasing order on basis of second element
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n==0)
            return 0;
        sort(points.begin(), points.end(), comp);
        int ans = 1;// number of arrows needed 
        int reach = points[0][1];
        for(int i=1; i<n; i++){
            // intervals will overlap when a[1] > b[0] ie a[end] > b[start]
            if(points[i][0] > reach){ // non overlap
                ans++;
                reach = points[i][1]; // update the new reach 
            }
        }
        return ans;
    }
};

// @lc code=start
// @lc code=end


int main(){

    return 0;
}