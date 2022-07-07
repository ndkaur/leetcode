/*
 * @lc app=leetcode id=1855 lang=cpp
 *
 * [1855] Maximum Distance Between a Pair of Values
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
class Solution0 {  //time limit exceeded  O(n^2)
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m= nums2.size();
        int mx=0;
        for(int i=0;i<n;i++){
            int dif=0;
            for(int j=i;j<m;j++){
                if(i<=j && nums1[i]<=nums2[j]){
                    dif= j-i;
                }
                mx= max(mx, dif);
            }
        }
        return mx;
    }
};

//  2 pointer
class Solution1 {  // o(n)
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m= nums2.size();
        int mx=0;
        int i=0,j=0;
        while(i<n && j<m){ 
            if(nums1[i]>nums2[j]){
                i++;
            }
            else { //55<100  n[i] < n[j]
                mx= max(mx, j-i);
                j++;
            }
        }
        return mx;
    }
};

// binary search 
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m= nums2.size();
        int mx=0;
        //  lenght of both arrays isnt always same 
        int k= min(n,m);

        for(int i=0;i<k;i++){
            // search for element in nums2 with target as element of num1
            int l= i; 
            int r= m-1;
            // simple bs -> mid>target  then we reduce the range means h= mid-1
            //  decresing order aray  100 mid target 10   mid> target then left reduce 
            while(l<=r){
                int mid= l+(r-l)/2;
                int target= nums1[i];
                if(nums2[mid]>= target){
                    l=mid+1;
                    //  difference check
                    if(mid-i>mx) 
                        mx =mid-i;
                }
                else 
                    r= mid-1;
            }
        }
        return mx;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums1={55,30,5,4,2};
    vector<int> nums2={100,20,10,10,5};
    int ans = sol.maxDistance(nums1, nums2);
    cout<<ans;
    return 0;
}