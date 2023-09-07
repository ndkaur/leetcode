/*
 * @lc app=leetcode id=1984 lang=cpp
 *
 * [1984] Minimum Difference Between Highest and Lowest of K Scores
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
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1 && k==1)
            return 0;
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 0;
        int mn =INT_MAX;
       
        while(j<n){
            if(j-i+1 < k){
                j++;
            }
            else{
                mn = min(mn, nums[j]-nums[i]);
                j++;
                i++;
            }
        }
        return mn;
    }
};

// @lc code=end


int main(){

    return 0;
}