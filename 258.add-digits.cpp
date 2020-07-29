/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
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
// class Solution {
// public:
//     int addDigits(int num) {
//         int sum =0;
//         while(num>0){
//             sum+=num%10;
//             num=num/10;
//             if(num==0 && sum>9){
//                 num =sum;
//                 sum=0;
//             }
//         }
//         return sum;
//     }
// };

class Solution{
    public:
        int addDigits(int num){
            if(num==0) return 0;
            if(num%9 ==0) return 9;
            return (num%9);
        }
};
// @lc code=end


int main(){
    Solution sol;
    int num=18;
    int sum=sol.addDigits(num);
    cout<<sum;
    return 0;
}