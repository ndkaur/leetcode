/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
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

//O(n)  O(n)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i=0;
        int j=0;
        while(i<m && j<n){
            if(nums1[i] < nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            ans.push_back(nums2[j]);
            j++;
        }      
        nums1 = ans;
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m+n-1; 
        int i= m-1;
        int j = n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[idx] = nums1[i];
                idx--;
                i--;
            }
            else {
                nums1[idx]=nums2[j];
                idx--;
                j--;
            }
        }
        while(i>=0){
            nums1[idx]=nums1[i];
            idx--;
            i--;
        }
        while(j>=0){
            nums1[idx]=nums2[j];
            idx--;
            j--;
        }
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums1={1,2,3,0,0,0};
    int m=3;
    vector<int> nums2 ={2,5,6};
    int n=3;
    sol.merge(nums1,m,nums2,n);
    print(nums1);
    return 0;
}