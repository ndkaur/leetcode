/*
 * @lc app=leetcode id=1331 lang=cpp
 *
 * [1331] Rank Transform of an Array
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
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copy(arr);
        sort(copy.begin(),copy.end());
        
        map<int,int> mp;
        for(int x:copy) 
            mp.emplace(x,mp.size()+1);

        for(int &x:arr)
            x=mp[x];
        return arr;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> arr={40,10,20,30};
    vector<int> copy =sol.arrayRankTransform(arr);
    print(copy);
    return 0;
}