/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
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
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2)
            return n;
        int ans = 0;
        for(auto itr1: points){ // (x1,y1)
            unordered_map<double,int> mp;
            double x1 = itr1[0];
            double y1 = itr1[1];
            for(auto itr2 : points){ // (x2,y2)
                if(itr2 == itr1) // when both i and j are at same idx 
                    continue;
                double x2 = itr2[0];
                double y2 = itr2[1];
                double slope;
                // slope -> m = y2-y1 / x2-x1
                if(x2-x1 == 0)
                    slope = INT_MAX;
                else 
                    slope = (y2-y1) / (x2-x1);

                mp[slope]++;
                ans = max(ans, mp[slope]);
            }
        }
        return ans+1;
    }
};


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2)
            return n;
        int ans = 0;
        for(int i=0; i<n; i++){ // (x1,y1)
            unordered_map<double,int> mp;
            double x1 = points[i][0];
            double y1 = points[i][1];
            for(int j=i+1; j<n; j++){ // (x2,y2)
                
                double x2 = points[j][0];
                double y2 = points[j][1];
                double slope;
                // slope -> m = y2-y1 / x2-x1
                if(x2-x1 == 0)
                    slope = INT_MAX;
                else 
                    slope = (y2-y1) / (x2-x1);

                mp[slope]++;
                ans = max(ans, mp[slope]);
            }
        }
        return ans+1;
    }
};
// @lc code=end


int main(){

    return 0;
}