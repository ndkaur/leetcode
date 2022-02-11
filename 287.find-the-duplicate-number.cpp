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

class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        int n= nums.size();
        map<int,int> count;
        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }
        for(auto itr=count.begin(); itr!=count.end();itr++){
            if(itr->second>=2)
                return itr->first;
        }
        return -1;
    }
};

class Solution2 {
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

// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,3,4,2,2};
    int ans= sol.findDuplicate(nums);
    cout<<ans;
    return 0;
}