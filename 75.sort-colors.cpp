/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
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

//  only 3 fix colors
// 0 in the beginign
//  1 in mid
//  2 must be at last 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l=0;
        int mid = 0;
        int h = n-1;

        while(mid<=h){
            if(nums[mid]==0){
                swap(nums[l], nums[mid]);
                l++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{// mid is 2
                swap(nums[mid], nums[h]);
                h--;
            }
        }
    }
};

// @lc code=end


int main(){

    return 0;
}