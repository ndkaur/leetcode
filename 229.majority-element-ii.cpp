/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
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
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        int req = n/3;
        vector<int> ans;
        for(auto itr:mp){
            if(itr.second>req){
                ans.push_back(itr.first);
            }
        }
        return ans;
    }
};


// moore vooting method
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int e1;
        int e2;
        int cnt1=0;
        int cnt2 =0;
        // this will give majority elems 
        for(auto num:nums){
            if(cnt1==0 && num!=e2){
                e1 = num;
                cnt1=1;
            }
            else if(cnt2==0 && num!=e1){
                e2 = num;
                cnt2=1;
            }
            
            else if(e1==num)
                cnt1++;
            else if(e2==num)
                cnt2++;

            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        cnt1=0;
        cnt2=0;

        for(int i=0; i<n; i++){
            if(e1==nums[i])
                cnt1++;
            if(e2==nums[i])
                cnt2++;
        }

        if(cnt1>n/3)
            ans.push_back(e1);
        if(cnt2>n/3)
            ans.push_back(e2);

        return ans;
    }
};

// @lc code=end


int main(){

    return 0;
}