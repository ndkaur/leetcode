/*
 * @lc app=leetcode id=1525 lang=cpp
 *
 * [1525] Number of Good Ways to Split a String
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
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
//     int numSplits(string s) {
//         int n= s.size();
//         int count=0;
//         string one;
//         string two;
//         int i=0;
//         for(int j=i;j<n;j++){
//             one=s.substr(i,j);
//             two = s.substr(j,n);
//             vector<int>hash(128);
//             int k=0,c=0;
//             for(k=0;k<one.size();k++)
//                 hash[one[k]]=1;
//             for(k=0;k<128;k++)
//                 c += hash[k];
//             hash.clear();
//             int l=0,m=0;
//             for(l=0;l<two.size();l++)
//                 hash[two[l]]=1;
//             for(l=0;l<128;l++)
//                 m += hash[l];
//             if(c==m)
//             count++;
//         }
//         return count;
//     } // doesnt work for last case if works then dont work for other case 
// };

//      a a c a b a
// pre  1 1 2 1 3 1
// suf  1 1 3 1 2 1

// check if pre[i-1] == suf[i]

class Solution1 {
public:
    int numSplits(string s) {
        int n= s.size();
        vector<int> pre(n),suf(n);
        map<char,int> freq;
        for(int i=0;i<n;i++){
            freq[s[i]]++;
            pre[i] = freq.size();
        }
        freq.clear();
        for(int i=n-1;i>=0;i--){
            freq[s[i]]++;
            suf[i] = freq.size();
        }
        int count=0;
        for(int i=1;i<n;i++){
            if(pre[i-1]==suf[i])
                count++;
        }
        return count;
    }
};

class Solution {
public:
    int numSplits(string s) {
        int n= s.size();
        unordered_map<char,int> mp1,mp2;
        for(auto c:s)
            mp1[c]++;
        int count=0;
        for(int i=0;i<n;i++){
            mp1[s[i]]--; // removing from one 
            mp2[s[i]]++; // adding to another 
            if(mp1[s[i]]==0) 
                mp1.erase(s[i]); // if complete existence is removed 
            if(mp2.size()==mp1.size())
                count++;
        }
        return count;
    }
};

// @lc code=end


int main(){
    Solution sol;
    string s ="acbadbaada";
    // string s="abcd";
    int ans = sol.numSplits(s);
    cout<<ans;
    return 0;
}