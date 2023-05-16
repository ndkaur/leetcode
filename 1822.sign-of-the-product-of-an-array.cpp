/*
 * @lc app=leetcode id=1822 lang=cpp
 *
 * [1822] Sign of the Product of an Array
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
    int arraySign(vector<int>& nums) {
        int n = nums.size();
        int cnt =0;
     
        for(int i=0; i<n; i++){
            if(nums[i] == 0)
                return 0;
            else if(nums[i]<0)
                cnt++;
        }

        if(cnt%2 == 1)
           return -1;
        return 1;
    }
}; 

// @lc code=end


int main(){

    return 0;
}