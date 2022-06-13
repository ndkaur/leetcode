/*
 * @lc app=leetcode id=828 lang=cpp
 *
 * [828] Count Unique Characters of All Substrings of a Given String
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

//  take hint fron 2262 leetcode question 
// @lc code=start
class Solution {
public:
    // const int m= 1e9+7;
    int uniqueLetterString(string s) {
        int n= s.size();
        vector<long long> l(n,-1);
        vector<long long> r(n,-1);
        vector<long long> lastL(26,-1);
        vector<long long> lastR(26,n);
        // left to right 
        for(int i=0;i<n;i++){
            int charAt= s[i]-'A';
            l[i] = i-lastL[charAt]; // if char repeat then subtract the duplicate substring
            lastL[charAt]=i; // saving the new apperance of current idx duplicate occurence
        }
        // right to left
        for(int i=n-1; i>=0; i--){
            int charAt= s[i]-'A';
            r[i]= lastR[charAt]-i;
            lastR[charAt]=i; // new occurence of duplicate 
        }

        int sum=0;
        for(int i=0;i<n;i++){
            sum= sum+(l[i] * r[i]);
        } 
        return sum;
    }
};
// @lc code=end


int main(){
    Solution sol;
    string s= "ABC";
    int sum= sol.uniqueLetterString(s);
    cout<<sum;
    return 0;
}