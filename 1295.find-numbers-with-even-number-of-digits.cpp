/*
 * @lc app=leetcode id=1295 lang=cpp
 *
 * [1295] Find Numbers with Even Number of Digits
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}
// NUMBERS WITH EVEN NO OF DIGITS:-
// @lc code=start
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int len=nums.size();
        int ans = 0;
        for(int i=0;i<len;i++){
            int count=0;
            // to count the no of digits in number
            while(nums[i]>0){
                nums[i]=nums[i]/10;
                count++;
            }
            // to check wether the count is even or not
            if(count%2==0)
                ans++;
        }
        return ans;
    }
};
// @lc code=end
int main(){
    Solution sol;
    vi nums;
    int count;
    nums={12,34,2,7896};
    cout<<sol.findNumbers(nums);
}