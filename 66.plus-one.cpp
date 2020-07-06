/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
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
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;
        while(n>=0){
            if(digits[n]==9){ // case of {1,2,3,9}
                digits[n]=0;
            }
            else{
                digits[n]+=1; // case of {1,2,3}
                return digits;
            }
            n--;
        }
        digits.insert(digits.begin(),1); //case of {9,9,9}
        return digits;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> digits={1,9,9,9};
    vector<int> ans=sol.plusOne(digits);
    print(ans);
    return 0;
}