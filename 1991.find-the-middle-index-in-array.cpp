/*
 * @lc app=leetcode id=1991 lang=cpp
 *
 * [1991] Find the Middle Index in Array
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
    int findMiddleIndex(vector<int>& nums) {
        int n= nums.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+= nums[i];
        }
        int sum=0;
        for(int i=0;i<n;i++){
            // we first check that if the ele is middle then its left side sum = right side sum
            int left= total-sum-nums[i];
            if(sum==left)
                return i;
            // if not equal then add the num[i]
            sum+= nums[i];
        }
        return -1;
    }
};
// @lc code=end



int main(){

    return 0;
}