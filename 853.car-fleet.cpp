/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
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

// make stack on basis of time 
// s= d/t   t= d/s 
// time = target- pos / speed


class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n= position.size();
        // made a single vi to store both {pos,speed} for each i
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({position[i],speed[i]});
        }

        sort(v.begin(), v.end());
        stack<double> stk; // monotonic decresing stack 
        vector<double> time(n);

        for(int i=0;i<n;i++){
           time[i] = (double)(target-v[i].first) / (double)v[i].second;
        }
        
        for(auto i=0;i<time.size();i++){
            while(stk.size() && stk.top() <= time[i]){
                stk.pop();
            }
            stk.push(time[i]);
        }
        
        return stk.size();
    }
};
// @lc code=end


int main(){
    Solution sol;
    int target= 10;
    vector<int> position= {6,8};
    vector<int> speed ={3,2};
    int ans = sol.carFleet(target, position, speed);
    cout<<ans;
    return 0;
}