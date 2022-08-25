/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
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


// time-> O( 2^n * k * n/2) // 2^n generat all subseq , k = inserting in ans ,  n/2 = is plaindrome 
// space-> O(k * x) // k= len of palindrome   , x = no of palindrome 

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        f(0, path, ans, s);
        return ans;
    }
    
    void f(int idx, vector<string>& path, vector<vector<string>>& ans, string s){
        int n= s.size();
        if(idx == n){
            ans.push_back(path);
            return;
        }
        for(int i=idx; i<n; i++){
            if(isPalindrome(idx, i, s)){
                // adding the palindrome substr( starting idx , ending idx )  idx , i 
                path.push_back(s.substr(idx, i-idx+1));
                f(i+1, path, ans, s);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(int start, int end, string& s){
        while(start<= end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end


int main(){
    
    return 0;
}