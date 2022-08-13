/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
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
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int l= -1;
        int r= n;
        while(1+l<r){
            int mid = l+(r-l)/2;
            if(nums[mid]== target)
                return mid;
            else if (nums[mid]>target){
                r= mid;
            }
            else 
                l= mid;
        }
        return -1;
    }
};

// @lc code=end


int main(){

    return 0;
}