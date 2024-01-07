/*
 * @lc app=leetcode id=446 lang=cpp
 *
 * [446] Arithmetic Slices II - Subsequence
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
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        // for each index we check diff with prev indexes 
        // and store that difference and its freq in a map 
        vector<unordered_map<long long, int>> dp(n); // diff , freq

        int ans = 0;

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                long long diff = (long long)nums[i] - nums[j];

                if(diff<INT_MIN || diff>INT_MAX)
                    continue;

                // now check if that diff already existed in the map of j
                //if theat diff exist at that jth index then add its freq  
                int cnt =  dp[j].count(diff) ? dp[j][diff] : 0;
                // add freq in ans 
                ans += cnt; 
                // update the freq+1 in the curr i
                dp[i][diff] += cnt + 1; // it is possible that same diffrence can occur in different j 
            }
        }
        return ans;
    }
};

// 0   1      2       3       4
// 2   4      6       8       10 
// 0   {2,1}  {4,1}   {6,1}   {8,1}
//            {2,2}   {4,1}   {6,1}
//                    {2,3}   {4,2}
//                            {2,4}
// 
// ans= 1 + 2 + 1 + 3 = 7

// @lc code=end


int main(){

    return 0;
}