/*
 * @lc app=leetcode id=1732 lang=cpp
 *
 * [1732] Find the Highest Altitude
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
    int largestAltitude(vector<int>& gain) {
        int n= gain.size();
        int ans=0;
        int mx=0;
        for(int i=0;i<n;i++){
            ans+= gain[i];
            mx= max(mx, ans)
        }
        return mx;
    }
};

// @lc code=end


int main(){

    return 0;
}