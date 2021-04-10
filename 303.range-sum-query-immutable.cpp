/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
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
class NumArray {
    vector<int> data;
public:
    NumArray(vector<int>& nums) {
        data =nums;
    }
    
    int sumRange(int left, int right) {
        int sum=0;
        for(int i=left;i<=right;i++){
            sum += data[i];
        }
        return sum;
    }
};


class NumArray1 {
    vector<int> accu;
public:
    NumArray(vector<int>& nums) {
        int n=num.size();
        accu.push_back(0);
        for(auto num:nums){
            accu.push_back(accu.back()+num);
        }
    }
    
    int sumRange(int left, int right) {
        return accu[right+1]-accu[left];
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end


int main(){
    NumArray numm;
    vector<int> nums={-2,0,3,-5,2,-1};
    
    return 0;
}