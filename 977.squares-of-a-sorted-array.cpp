/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start


class Solution0 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++){ 
            ans[i] = (nums[i]) * (nums[i]);
        }
        sort(ans.begin(), ans.end()); //nlogn 
        return ans;
    }
};

// two pointer O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i =0;
        int j =n-1;
        vector<int> ans(n);
        int k = n-1;
        while(i<=j){
            if(abs(nums[i]) > abs(nums[j])){
                ans[k]= pow(nums[i],2);
                k--;
                i++;
            }
            else { //j>i
                ans[k] = pow(nums[j],2);
                k--;
                j--;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int len =A.size();
        vi out;
        for(int i=0;i<len;i++){
           int sq=A[i]*A[i];
           out.push_back(sq);
        }
        sort(out);
        return out;
    }

    void sort(vi &A){
        int len = A.size();
        for(int i=0; i<len-1; i++){
            for(int j=0;j<len-i-1;j++){
               if(A[j]>A[j+1])
                 swap(A[j],A[j+1]);
            }
        }
    }
};
// @lc code=end
int main(){
    Solution sol;
    vi out,A;
    int i,j;
    A={-4,-1,0,3,10};
    out=sol.sortedSquares(A);
    print(out);

    return 0;
}