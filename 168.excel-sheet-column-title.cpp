/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
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
class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while(n){
            ans = char('A' + (n-1) %26) +ans;
            n = (n-1)/26;
        }
        return ans;
    }
};

// n = 28  ans = A + 27 %26 =  A + 1 = 26+1 =27 = B =ans
// n = 27/26 = 1 
// ans = A + (1-1)%26 + ans = A+ans = A+B =AB

// @lc code=end


int main(){

    return 0;
}