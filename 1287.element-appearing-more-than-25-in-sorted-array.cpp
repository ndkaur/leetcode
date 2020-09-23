/*
 * @lc app=leetcode id=1287 lang=cpp
 *
 * [1287] Element Appearing More Than 25% In Sorted Array
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

class Solution1 {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n =arr.size();
        map<int,int> count;
        for(auto x: arr) 
            count[x]++;
        int mx = 0;
        for(auto p: count){
            mx = max(mx, p.second);
        }
        for(auto p: count){
            if(p.second==mx) 
                return p.first;
        }
        return -1;
    }
};

// vector<pair<int,int>> save;
// for(auto p: count){
//     save.push_back(p);
// }
// sort(save.begin(), save.end(), [&](pii &p1, pii &p2){
//     return p1.second>p2.second;
// });
// print_vp(save);
//     return save.back().first;
    
// @lc code=end

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n =arr.size();
        for(int i=0;i<3*n/4;i++){
            if(arr[i]==arr[i+n/4]) 
                return arr[i];
        }
        return arr[0];
    }
    
};


int main(){
    Solution sol;
    vi arr = {1,2,2,6,6,6,6,7,10};
    int ans = sol.findSpecialInteger(arr); 
    deb(ans);
    return 0;
}
