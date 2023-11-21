/*
 * @lc app=leetcode id=1887 lang=cpp
 *
 * [1887] Reduction Operations to Make the Array Elements Equal
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
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt =0;
        // 0 1 2 3 4
        // 1 1 2 2 3 
        // i=3 -> 2 != 3 -> cnt = number of nums till that index =5-3 =  2 
        // 1 1 2 2 2 
        // i=2 -> 1 != 2 -> cnt = n-i = 5-2 = 3 
        // cnt= 3
        sort(nums.begin(), nums.end());
        for(int i=n-1; i>0; i--){
            if(nums[i-1]!=nums[i]){
                cnt += n-i;
            }
        }
        return cnt;
    }
};

// @lc code=end


int main(){

    return 0;
}