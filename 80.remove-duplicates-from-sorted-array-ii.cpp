/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
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
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        if(n==0) return 0;
        int count=0;
        for(int i=2;i<n;i++){
            if(nums[i]==nums[i-2-count])
                count++; // check repeatence 
            else 
                nums[i-count]=nums[i]; // difference of 2 from i 
                // term behind by 2 from is relaced by the i.
        }
        return n-count;
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        int i=0;
        int j=0;

        while(i<n){
            int curr = nums[i];
            int cnt = 0;
            while(i<n && nums[i]==curr){
                cnt++;
                i++;
            }
            if(cnt>1){ // take only 2 occurence
                nums[j] = curr;
                j++;
                nums[j] = curr;
                j++;
            }
            else{
                nums[j] = curr;
                j++;
            }
        }
        return j;
    }
};

// @lc code=end


int main(){
    
    return 0;
}