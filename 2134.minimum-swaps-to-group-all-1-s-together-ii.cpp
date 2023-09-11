/*
 * @lc app=leetcode id=2134 lang=cpp
 *
 * [2134] Minimum Swaps to Group All 1's Together II
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
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int ones =0;
        for(int num:nums){
            if(num==1)
                ones++;
        }
        if(ones==0)
            return 0;

        for(int i=0; i<n; i++){
            nums.push_back(nums[i]);
        }

        n= n*2;

        int i =0;
        int j =0;
        int cnt =0;
        
        int ans = INT_MAX;
        while(j<n){
            // considering the window size as the number of ones existing
            if(j-i+1 < ones){
                if(nums[j]==1)
                    cnt++;
                j++;
            }
            else if(j-i+1 == ones){
                if(nums[j]==1)
                    cnt++;
                
                ans = min(ans, ones-cnt);

                if(nums[i]==1)
                    cnt--;
                // always maintiaing the window of size = no of ones
                i++;
                j++;
            }
        }
        return ans;
    }
};
// @lc code=end


int main(){

    return 0;
}