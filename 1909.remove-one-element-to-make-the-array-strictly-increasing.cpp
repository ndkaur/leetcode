/*
 * @lc app=leetcode id=1909 lang=cpp
 *
 * [1909] Remove One Element to Make the Array Strictly Increasing
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
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        int lcnt = 0;
        int prev = nums[0];
        for(int i=1; i<n; i++){
            if(prev < nums[i]) // increasing order
                prev = nums[i];
            else 
                lcnt++;
        }

        int rcnt=0;
        int last = nums[n-1];
        for(int i=n-2; i>=0; i--){
            if(last > nums[i]) // decreasing order
                last = nums[i];
            else 
                rcnt++;
        }
        return min(lcnt,rcnt) <= 1 ? true : false;
    }
};

// @lc code=end


int main(){

    return 0;
}