/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
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
//  brute force t->O(2^m+n)  s->O(m+n)
class Solution0 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())
            return false;
        string res;
        return is_check(s1,s2,0,0,res,s3);
    }
    bool is_check(string& s1, string& s2, int i, int j, string res, string& s3){
        if(res==s3 && i== s1.size() && j==s2.size())
            return true; // i and j reached at end 
        int ans = false;
        if(i<s1.size())
            ans |= is_check(s1, s2, i+1,j, res+s1[i], s3);
        if(j<s2.size())
            ans |= is_check(s1, s2, i, j+1, res+s2[j], s3);
        return ans;
    }
};

// class Solution1 {
//     unordered_map<string,bool> mem;
//     bool check(string s1,string s2,string s3,int len1,int len2,int len3,int p1,int p2,int p3)
//     {
//         if(p3==len3)
//             return (p1==len1 and p2==len2)?true:false;
        
//         string key = to_string(p1)+"*"+to_string(p2)+"*"+to_string(p3);
//         if(mem.find(key)!=mem.end())
//             return mem[key];
        
//         if(p1==len1)
//             return mem[key] = s2[p2]==s3[p3]? check(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1):false;
//         if(p2==len2)
//             return mem[key] = s1[p1]==s3[p3]? check(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1):false;
        
//         bool one = false,two = false;
//         if(s1[p1]==s3[p3])
//             one = check(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1);
//         if(s2[p2]==s3[p3])
//             two = check(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1);
        
//         return mem[key] = one or two;
//     }
// public:
//     bool isInterleave(string s1, string s2, string s3) {
//         int len1 = s1.length();
//         int len2 = s2.length();
//         int len3 = s3.length();
//         if(len3 != len1+len2)
//             return false;
        
//         return check(s1,s2,s3,len1,len2,len3,0,0,0);
//     }
// };

// best solution 
// class Solution {
// public:
//     bool isInterleave(string s1, string s2, string s3) {
//         if(s3.length() != s1.length() + s2.length())
//             return false;
//             // dp table 
//             bool table[s1.length()+1][s2.length()+1];
//             for(int i=0; i<s1.length()+1; i++)
//                 for(int j=0; j< s2.length()+1; j++){
//                     if(i==0 && j==0)
//                         table[i][j] = true;
//                     else if(i == 0) // filled with j 
//                         table[i][j] = ( table[i][j-1] && s2[j-1] == s3[i+j-1]);
//                     else if(j == 0) // filed with i
//                         table[i][j] = ( table[i-1][j] && s1[i-1] == s3[i+j-1]);
//                     else // both i and j 
//                         table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1] ) || (table[i][j-1] && s2[j-1] == s3[i+j-1] );
//                 }
//             return table[s1.length()][s2.length()];
//     }   
// };


// ...............................................

//  recursion 
class Solution {
public:
    bool helper(string& s1, string& s2, string &s3, int l1, int l2, int l3) {
        if(l1<0 && l2<0 && l3<0) {
            return true;
        }
        if(l1>=0 && s1[l1]==s3[l3] && l2>=0 && s2[l2]==s3[l3] ) {
            return (helper(s1, s2, s3, l1-1, l2, l3-1) || helper(s1, s2, s3, l1, l2-1, l3-1));
        }
        else if(l1>=0 && s1[l1]==s3[l3])
            return helper(s1, s2, s3, l1-1, l2, l3-1);
        
        else if(l2>=0 &&s2[l2]==s3[l3])
            return helper(s1, s2, s3, l1, l2-1, l3-1);
        
        else return false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size())
			return false;
        return helper(s1, s2, s3,s1.size()-1, s2.size()-1, s3.size()-1);
    }
};

//  memoization -> O(n*m)  s->O(n*m)+ o(m+n)
class Solution {
public:
    
    bool ischeck(int l1, int l2, int l3, string& s1, string& s2, string& s3, vector<vector<int>>& dp){
        
        if(l1<0 && l2<0 && l3<0){
            return true;
        }
        if(l1>=0 && l2>=0 && dp[l1][l2]!=-1)
            return dp[l1][l2];
        
        //  when equal
        if(l1>=0 && s1[l1]==s3[l3] && l2>=0 && s2[l2]==s3[l3]){
            return dp[l1][l2]= (ischeck(l1-1,l2,l3-1,s1,s2,s3,dp) || ischeck(l1,l2-1,l3-1,s1,s2,s3,dp));
        }
        //  if only one equal
        else if(l1>=0 && s1[l1]==s3[l3]){
            return ischeck(l1-1, l2, l3-1, s1, s2, s3, dp);
        }

        else if(l2>=0 && s2[l2]==s3[l3]){
            return  ischeck(l1, l2-1, l3-1, s1,s2, s3, dp);
        }
        else 
            return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int len1= s1.size();
        int len2= s2.size();
        int len3= s3.size();
        
        if(len3!= len1+len2 )
            return false;
        vector<vector<int>>dp(len1+1, vector<int>(len2+1,-1));
        return ischeck(len1-1,len2-1,len3-1,s1, s2, s3, dp);
    }
};






// @lc code=end


int main(){
    Solution sol;
    string s1="a";
    string s2= "b";
    string s3= "ab";
    bool ans= sol.isInterleave(s1,s2,s3);
    cout<<ans;
    return 0;
}