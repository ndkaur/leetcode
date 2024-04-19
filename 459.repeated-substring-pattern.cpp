/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
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



class Solution0 {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        // we can only take len of substring upto n/2
        // i represen the len we can take of substring  
        for(int i=1; i<=n/2; i++){
            // no of divisior 2 * root n
            if(n%i==0){
                int times = n/i;
                string temp = s.substr(0,i); // worst case O(N)
                string newStr = "";
                while(times--){ // O(N)
                    newStr +=temp;
                }
                if(newStr==s)
                    return true;
            }
        }
        return false;
    }
};
// so total time complexity:-  O(2*rootN) * O(2N) ~ O(root N * N)
// number of divisior for any num = 2 root n

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        // we can only take len of substring upto n/2
        for(int i=n/2; i>=1; i--){
            if(n%i==0){
                int times = n/i;
                string temp = s.substr(0,i);
                string newStr = "";
                while(times--){
                    newStr +=temp;
                }
                if(newStr==s)
                    return true;
            }
        }
        return false;
    }
};



//O(n^2)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n  = s.size();
        // abab 
        string temp = s;
        for(int i=0; i<n-1; i++){
            char c = temp[0];
            temp.erase(0,1);
            temp.push_back(c);

            if(temp==s)
                return true;
        }
        return false;
    }
};

// O(n)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        //double the string 
        // create a substr 
        // find the original string in the substring 
        return (s+s).substr(1, 2*s.size()-2).find(s) != -1 ;
        // if the s exist then it will occur in the center 
        // abab 
        //abab abab  substr => babab  => s= abab it exist
        // we remove the first elem form start and last elem then take the elems inbetween 
        
    }
};
// @lc code=end


int main(){
    Solution sol;
    string s="aba";
    bool ans=sol.repeatedSubstringPattern(s);
    cout<<ans;
    return 0;
}