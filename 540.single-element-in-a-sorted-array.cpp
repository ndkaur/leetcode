/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
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
    int singleNonDuplicate(vector<int>& nums) {
        int n= nums.size();
        map<int,int> count;
        for(int n:nums){
            count[n]++;
        }
        int ans=0;
        for(auto itr=count.begin();itr!=count.end();itr++){
            if(itr->second==1)
                ans =itr->first;
        }
        return ans;
    }
}; // o(n)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0]; // first element
        if(nums[n-1]!=nums[n-2]) return nums[n-1]; // last element 
        int low =1;
        int high= n-2;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])// if mid the the element
                return nums[mid]; 
            // if mid is at even index
            if(mid%2==0){ // even 
                if(nums[mid]== nums[mid-1]) // odd, even
                    high = mid-1;
                if(nums[mid]== nums[mid+1]) // even , odd 
                    low= mid+1;
            }
            if(mid%2==1){ // odd
                if(nums[mid]== nums[mid-1]) // even odd 
                    low = mid+1;
                if(nums[mid]== nums[mid+1]) // odd even
                    high= mid-1;
            }
        }
        return -1;
    }
};
//  even odd even odd even odd even odd


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n= nums.size();
        int low = 0;
        int high = n-1;
        if(high==0) return nums[0];
        if(nums[0]!=nums[1]) return  nums[low];
        if(nums[high]!= nums[high-1]) return nums[high];

        while(low<=high){
            int mid= low+(high-low)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!= nums[mid+1]) 
                return nums[mid];
            //   even index   
            if(((mid%2==0) && (nums[mid]==nums[mid+1])) || ((mid%2==1) && (nums[mid]==nums[mid-1]))){
                low= mid+1;
            }
            else 
                high = mid-1;
        }
        return -1;
    }
};

// even odd even odd even odd even odd

// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,1,2,3,3,4,4,8,8};
    int ans = sol.singleNonDuplicate(nums);
    cout<<ans;
    return 0;
}