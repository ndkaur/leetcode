/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
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

//  max water stored at any point is the min(max hight of left , max height of right ) - curr height 

// burute force ->O(N)
// space -> O(2N) 
class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        // finding the left max 
        int ml=0;
        vector<int> left(n);
        for(int i=0;i<n;i++){
            if(ml < height[i]){
                ml = height[i];
            }
            left[i]= ml;
        }

        // finding the right mx height 
        int mr=0;
        vector<int> right(n);
        for(int i=n-1;i>=0;i--){
            if(mr < height[i]){
                mr =  height[i];
            }
            right[i]= mr;
        }

        int ans=0;
        // min(mr, ml) - height[i]
        for(int i=0;i<n;i++){
            ans += min(left[i],right[i]) - height[i];
        }
        return ans;
    }
};


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> l(n);
        vector<int> r(n);
        l[0] = height[0];
        for(int i=1; i<n; i++){
            l[i] = max(height[i], l[i-1]);
        }
        r[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            r[i] = max(height[i], r[i+1]);
        }
        int ans =0;
        for(int i=0; i<n; i++){
            ans += min(l[i], r[i]) - height[i];
        }
        return ans;
    }
};

// two pointer 
class Solution { //O(n), O(1)
public:
    int trap(vector<int>& height) {
        int n= height.size();
        int ans=0;
        int lmax=0;
        int rmax=0;
        int l=0;
        int r= n-1;
        while(l<r){
            if(height[l] <= height[r]){
                if(lmax <= height[l]) // update lmax
                    lmax = height[l];
                else 
                    ans += lmax - height[l];
                l++;
            }
            else {  // height[l] > height[r]
                if(rmax <= height[r]) // update rmax
                    rmax = height[r];
                else 
                    ans+= rmax- height[r];
                r--;
            }
        }
        return ans; 
    }
};



// @lc code=end


int main(){

    return 0;
}