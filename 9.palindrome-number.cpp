/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
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

class Solution { //O(N)  O(N)
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        string s = to_string(x);
        cout<<s<<endl;
        string r= s;
        reverse(r.begin(), r.end());
        cout<<r<<endl;
        for(int i=0;i<s.size(); i++){
            if(s[i]!=r[i])
                return false;
        }
        return true;
    }
};


class Solution { // o(logn)  O(1)
public:
    bool isPalindrome(int x) {
        // -ve num or num with 00 like 10 100 1000
        if(x<0 || x%10 == 0 && x!=0) 
            return false;
        int revNum=0;
        // 12321
        while(x > revNum){
            int rem = x%10;
            revNum  = revNum * 10 + rem;
            x= x/10;
        }
        // even num ->1221  x= 12  rev = 12
        // odd len ->12321   x= 12  rev 123 sor the mid 3 doesnot matter we can drop it off
        return x == revNum ||  x == revNum/10;
    }
};

// @lc code=end


int main(){
    Solution sol;
    int x= 100;
    bool ans = sol.isPalindrome(x);
    cout<<ans;
    return 0;
}