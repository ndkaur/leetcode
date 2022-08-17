/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
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

// brute force > merge sort -> take two ptr pick whats smaller O(N1 +N2) 
// can reduce a little -> by making a count and only picking till len half 


// int l1 = p1==0 ? INT_MIN : nums1[p1-1];
// int l2 = p2==0 ? INT_MIN : nums2[p2-1];
            
// int r1 = p1==n1 ? INT_MAX : nums1[p1];
// int r2 = p2==n2 ? INT_MAX : nums2[p2];


class Solution { // log(min(n1,n2))  sc->O(1)
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       // do in accordance to smaller leng array 
        int n1= nums1.size();
        int n2= nums2.size();
        if(n1>n2)
            return findMedianSortedArrays(nums2, nums1);
        // doing for n1 < n2
        int start = 0;
        int end = n1; // taking the partition indexes
        while(start <= end){
            int p1= start+(end-start)/2;
            int p2= ( (n1+n2+1)/2 ) - p1;  // total len half - p1
            // ading 1 will handle both even and odd cases 

            int l1 = INT_MIN; // cause we want max val of l  g
            int l2= INT_MIN;
            int r1 =INT_MAX; // we want min val of r
            int r2= INT_MAX;

            if(p1>0)
                l1= nums1[p1-1];
            if(p2>0)
                l2= nums2[p2-1];

            if((p1>=0) && (p1<n1))
                r1= nums1[p1];

            if((p2>=0) && (p2<n2))
                r2= nums2[p2];

            if(l1<=r2 && l2<=r1){// valid partition
                // even len
                if((n1+n2) % 2 == 0){
                    return  (max(l1,l2)+ min(r1,r2)) /2.0;
                }
                else // odd len only one mid ele
                    return max(l1,l2);
            }
            // only care about situation of smaller array which is num1
            else if(l1 > r2){ // l1 is very large , have to reduce l1  so to reduce move high
                end = p1-1;
            } 
            else { // l2>r1  // r1 is very small , have to increase it , so move left
                start = p1+1;
            }
        }
        return 0;
    }
};

// @lc code=end


int main(){

    return 0;
}