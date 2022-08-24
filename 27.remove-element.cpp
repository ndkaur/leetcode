/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
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
    int removeElement(vector<int>& nums, int val) {
        int n= nums.size();
        int i=0;
        for(int j=0;j<n;j++){
            if(nums[j]!= val){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

// 0 1 2 3 4 5 6 7
// 0 1 2 2 3 0 4 2

// i=0 , j=0  0!=2 so i++ replace nums[i]= nums[j]
// i=1 , j=1  1!=2 so i++ replace  0 1 2 2 3 0 4 2
// i=2 , j=2  2==2 so do nothing 
//  i=2 , j=3 2==2 so do nothing 
// i=2 , j=4  3!=2  so i++ and replace 0 1 3 2 3 0 4 2
// i=3  j=5  0!=2  s i++ and replace   0 1 3 0 3 0 4 2
// i=4 j=6 4!=2  so i++ and replace    0 1 3 0 4 0 4 2
// i=5 j=7  2==2 so do nothing 
// end of array  return i 


// @lc code=end


int main(){

    return 0;
}