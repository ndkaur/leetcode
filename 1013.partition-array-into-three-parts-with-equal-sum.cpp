/*
 * @lc app=leetcode id=1013 lang=cpp
 *
 * [1013] Partition Array Into Three Parts With Equal Sum
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
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int len = A.size();
        int sum=0;
        for(int i=0;i<len;i++){
            sum=sum+A[i];
        }
        if(sum%3!=0)
            return false;
        if(sum==0 && len>4)
            return true;
        
        int subsum=sum/3; // 9/3 = 3
        
        int add=0;int count=0;
        for(int i=0;i<len;i++){
            add=add+A[i];
            if(add==subsum){
                add=0;
                count++;
            }
            if(count==3 && i==len-1){
                return true;
            }

        }
        return false;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> A={10,-10,10};
    bool out=sol.canThreePartsEqualSum(A);
    cout<<out;
    return 0;
}