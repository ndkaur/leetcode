/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> help;
        vector<int> out;
        map<int,int> ans;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!help.empty() && help.back()<=nums2[i]){
                help.pop_back();
            }
            if(help.empty()){
                ans[nums2[i]]= -1;
            }
            else{
                ans[nums2[i]]= help.back();
            }
            
            help.push_back(nums2[i]);
        }

        for(auto x:nums1){
            out.push_back(ans[x]);
        }
        return out;
    }
};

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    int mx =-1;
                    for(int k=j;k<nums2.size();k++){
                        if(nums2[k]>nums2[j]){
                            mx = nums2[k];
                            break;
                        }
                    }
                    ans.push_back(mx);
                }
            }
        }
        return ans;
    }
};

// with help of stack we find next greater ele for each nums2[i]
// then  we iterate to the nums1[i]  to get its val stored in ans
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int> mp; // key - >idx
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=i;
        }
        // 1->0   3->1, 4->2 , 2->3
        
        vector<int> ans(nums2.size(),-1);
        // find the next greater ele for nums2
        stack<int> stk; // stk will store the indexes + mon dec stack
        
        for(int i=0;i<nums2.size();i++){
            while(!stk.empty() && nums2[stk.top()] < nums2[i]){
                ans[stk.top()] = nums2[i];
                stk.pop();
            }
            stk.push(i);
        }
        
        
        
        vector<int> res(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++){
            res[i] = ans[mp[nums1[i]]];   //ans[mp[nums[0]]] -> ans[mp[4]] -> ans[2]
        }
        return res;
    }
};


// @lc code=end


int main(){
    Solution sol;
    vector<int> nums1={4,1,2};
    vector<int> nums2={1,3,4,2};
    vector<int> out=sol.nextGreaterElement(nums1,nums2);
    print(out);
    return 0;
}