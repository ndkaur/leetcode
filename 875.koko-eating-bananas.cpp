/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
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
    int minEatingSpeed(vector<int>& piles, int h) {
        int n= piles.size();
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(possible(piles, h, mid)== true){
                ans=mid;
                r= mid-1;
            }else 
                l=mid+1;
        }
        return ans;
    }
    bool possible(vector<int>&piles,int h, int mid){
        int n= piles.size();
        int count=0;
        for(int i=0;i<n;i++){
            count+= ceil((piles[i]*1.0)/mid);
        }
        if(count<=h)
            return true;
        return false;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> piles={3,6,7,11};
    int h=8;
    int ans= sol.minEatingSpeed(piles,h);
    cout<<ans;
    return 0;
}