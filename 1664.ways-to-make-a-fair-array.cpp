/*
 * @lc app=leetcode id=1664 lang=cpp
 *
 * [1664] Ways to Make a Fair Array
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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}

// @lc code=start

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n= nums.size();
        int reven =0, rodd=0;
        for(int i=0;i<n;i++){// total even and odd sum
            if(i%2==0){
                reven+= nums[i];
            }else{
                rodd+= nums[i];
            } 
        }
        int count=0;
        int leven =0,lodd=0;
        for(int i=0;i<n;i++){
            if(i%2==0){ // removing the num one by one 
                reven-= nums[i];
            }else{
                rodd-= nums[i];
            }
            if(reven+lodd==rodd+leven){ // checking if by removing hun the sum get equal
                count++;
            }
            if(i%2==0){ // adding the removed nums in left count
                leven+=nums[i];
            }else 
                lodd+= nums[i];
        }
        return count;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,1,1};
    int ans = sol.waysToMakeFair(nums);
    cout<<ans;
   return 0;
}