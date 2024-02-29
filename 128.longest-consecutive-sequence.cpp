/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
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
// brute :- O(n^2)
class Solution0 {
public:
    bool search(vector<int>& nums, int val){
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==val)
                return true;
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        int longest= 1;
        for(int i=0; i<n; i++){
            int num = nums[i];
            int cnt =1;
            while(search(nums, num+1)){
                num += 1;
                cnt++;
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};

// best approach :- //O(nlogn) + O(n)
class Solution1 {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;

        sort(nums.begin(), nums.end());

        int small = INT_MIN;
        int cnt = 0;
        int longest= 1;

        for(int i=0; i<n; i++){
            if(nums[i]-1==small){
               cnt+=1;
               small = nums[i];
            }
            else if(nums[i]!=small){ // giving small value 
                cnt=1;
                small = nums[i];
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};


class Solution { // O(n)+ O(2*n)
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;

        int longest =1;
        unordered_set<int> st;
        for(int i=0; i<n; i++){ //O(n)
            st.insert(nums[i]);
        }

        for(auto itr:st){ //O(2*n)
            // itr is starting num 
            if(st.find(itr-1)==st.end()){
                int cnt = 1;
                int val = itr;
                // finding next num of itr 
                while(st.find(val+1)!=st.end()){
                    val =  val+1;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};

// .....................................................................................

class Solution0 {
public:
    int longestConsecutive(vector<int>& nums) {
        int n= nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int curr=1;
        int longest=1;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                if(nums[i]==nums[i-1]+1)
                    curr+=1;
                else{
                    longest = max(curr, longest);
                    curr=1;
                }
            }
        }
        return max(curr, longest);
    }
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n= nums.size();
        if(n==0) return 0;
        unordered_set<int> s;
        for(int i:nums){
            s.insert(i);
        }
        int curr=1;
        int longest=1;
        
        for(int num:s){
            if(!s.count(num-1)){
                curr=0;
                while(s.count(num)){
                    curr++;
                    num = num+1;
                }
                longest= max(curr, longest);
            }
        }
        return longest;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={};
    int ans = sol.longestConsecutive(nums);
    cout<<ans;
    return 0;
}