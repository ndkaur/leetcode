/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
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
class Solution0 {
public:
    int findDuplicate(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int> count;
        int ans;
        for(int i=0;i<n;i++){
            count[nums[i]]++;
            if(count[nums[i]]>1){
                ans= nums[i];
                break;
            }
        }
        return ans;
    }
};



class Solution { // binary search 
public:
    int findDuplicate(vector<int>& nums) {
        int n= nums.size();
        int l=1;
        int h= n-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            int count=0;
            for(int x:nums){
                if(x<=mid) 
                    count++;
            }
            if(count<=mid)
                l= mid+1;
            else 
                h= mid-1;
        }
        return l;
    }
};


class Solution { //O(N)   sc->O(N)
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for(int num:nums)
            mp[num]++;
        for(auto itr:mp)
            if(itr.second>1)
                return itr.first;
        return 0;
    }
};

// slow and fast ptrs 

class Solution { //O(N)   sc->O(1)
public:
    int findDuplicate(vector<int>& nums) {
        int slow= nums[0];
        int fast = nums[0];
        // moving ahead value to inde wise 
        // i= 0 val = 3 then go to idx 3
        do{
            slow= nums[slow];
            // move by speed of 2
            fast= nums[nums[fast]];
        }while(slow!=fast);
        // again set fast to starting 
        fast= nums[0];
        while(slow!=fast){
            // both move by 1 step ahead 
            slow= nums[slow];
            fast= nums[fast];
        }
        return fast;
    }
};


// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,3,4,2,2};
    int ans= sol.findDuplicate(nums);
    cout<<ans;
    return 0;
}