/*
 * @lc app=leetcode id=1465 lang=cpp
 *
 * [1465] Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
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

// Time Complexity: O(N * log(N) + M * log(M)) where N is the length of hc and M is the length of vc
// Space Complexity: O(1)

class Solution {
public:
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
        int n= hCuts.size();
        int m= vCuts.size();

        sort(hCuts.begin(), hCuts.end());
        sort(vCuts.begin(), vCuts.end());
        //  finding the space above the first cut and below the last cut 
        int maxh= max(hCuts[0], h-hCuts.back());
        int maxv= max(vCuts[0],w-vCuts.back());

        //  findind the space in between the cuts 
        for(int i=1;i<n;i++){
            maxh= max(maxh, hCuts[i]-hCuts[i-1]);
        }
        for(int j=1;j<m;j++){
            maxv= max(maxv, vCuts[j]- vCuts[j-1]);
        }
        return (int)((long)maxh* maxv % 1000000007);
    }
};
// @lc code=end


int main(){

    return 0;
}