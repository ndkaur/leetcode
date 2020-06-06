/*
 * @lc app=leetcode id=1389 lang=cpp
 *
 * [1389] Create Target Array in the Given Order
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int len=nums.size();
        vector<int> target;
        target.assign(len,-1);
        for(int i=0;i<len;i++){
            int pos=index[i];
            int val=nums[i];
            if(pos==-1)
              pos=val;
            else{
                while(pos<len && val!=-1){
                    int temp=target[pos];
                    target[pos]=val;
                    val=temp;
                    pos++;
                }
            }
        }
        return target;
    }
};
// @lc code=end

// class Solution {
// public:
//     vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
//         int len=nums.size();
//         vector<int> target;
//         for(int i=0;i<len;i++){
//             int pos=index[i];
//             int val=nums[i];
//             target.insert(target.begin()+pos,val);
//         }
//         return target;
//     }
// };

int main(){
    Solution sol;
    vi nums,index,target;
    nums = {1,2,3,4,0}; 
    index ={0,1,3,2,0};
    target=sol.createTargetArray(nums,index);
    print(target);
    return 0;
}