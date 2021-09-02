/*
 * @lc app=leetcode id=565 lang=cpp
 *
 * [565] Array Nesting
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
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
class Solution0 {
public:
    int arrayNesting(vector<int>& nums) {
        int n= nums.size();
        vector<bool> seen(n);
        int ans=0;
        for(int i=0;i<n;i++){
            int count=0;
            while(!seen[i]){
                seen[i] =true;
                count++;
                i=nums[i];
            }
            ans = max(ans,count);
        }
        return ans;
    }
};

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n= nums.size();
        int ans =0;
        int cur, prev , count;
        for(int i=0;i<n;i++){
            if(nums[i]==-1) continue;
            cur= nums[i];
            count=1;
            nums[i]=-1;
            while(nums[cur]!=-1){ // when the nums start repating -1 will tell taht its already visitedcc
                prev=cur; // for saving its value 
                cur= nums[cur]; // giving it next value 
                nums[prev]=-1; // marking its already visited 
                count++;
            }
            ans = max(ans , count);
        }
        return ans ;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={5,4,0,3,1,6,2};
    int ans = sol.arrayNesting(nums);
    cout<<ans;
    return 0;
}