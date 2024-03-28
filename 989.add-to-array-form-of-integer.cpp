/*
 * @lc app=leetcode id=989 lang=cpp
 *
 * [989] Add to Array-Form of Integer
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        int carry = 0;
        int i = n-1;
        while(i>=0){
            // 1200  k = 34 -> sum = 0 + 4 = 4
            int sum = num[i] + k%10 + carry;
            k=k/10;
            // adding sum to array , summ can be double digit so maintitn carry
            num[i] =  sum%10;
            i--;
            carry = sum/10;
        }
        // k value still remaining -> add sum infront of array
        while(k>0){
            int sum = k%10 + carry;
            k = k/10;
            num.insert(num.begin(), sum%10);
            carry = sum/10;
        }

        if(carry>0)
            num.insert(num.begin(), carry);
        return num;
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<int> A={1,2,0,0};
    int k;
    vector<int> out=sol.addToArrayForm(A,34);
    print(out);
    return 0;
}