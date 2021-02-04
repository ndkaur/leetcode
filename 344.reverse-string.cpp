/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
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
//     void reverseString(vector<char>& s) {
//         int n = s.size();
//         int left=0;
//         int right=n-1;
//         while(left<right){
//             char temp =s[left];
//             s[left]=s[right];
//             s[right]=temp;
//             left++;
//             right--;
//         }
//     }
// };

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        reverse (s,n, 0, n-1);
    }
    void reverse(vector<char> &s , int n, int left, int right){
        if(left>=right) return ;
        char temp = s[left];
        s[left++]=s[right];
        s[right--]=temp;
        reverse(s, n, left, right);
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<char> s= {'h','e','l','l','o'};
    sol.reverseString(s);
    for(auto c: s){
        cout<<c;
    }
    return 0;
}