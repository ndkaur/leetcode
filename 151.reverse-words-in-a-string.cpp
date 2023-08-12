/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
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

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start

class Solution {
public:
    string reverseWords(string s) {
        s+=" "; // so that we can add hte last char int he string ans as well
        string temp="";
        string ans="";
        for(int i=0; i<s.size(); i++){
            if(s[i]!=' '){
                temp+=s[i]; // the
            }
            else if(s[i]==' ' && temp.size()>0){
                reverse(temp.begin(), temp.end()); // eht
                ans+= temp+" ";
                temp="";
            }
            //ans = eht ysk si eulb
        }
        ans.pop_back(); // removing extra space
        reverse(ans.begin(), ans.end());// it reverse each word and the full string as well
        // bule  is the sky 
        return ans;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans;
        int  i=0;
        while(i<n){
            // so we keep a check at i to check if there are any continous spaces 
            while(i<n && s[i]== ' '){
                i++;
            }
            // i is always at the first char after the space 
            if(i >= n)
                break;
            int j = i+1;
            while(j<n && s[j] != ' '){
                j++;
            }
            //after this while loop the j reaches the space after the last char of the word  ->  sky _
            string sub = s.substr(i, j-i);
            
            if(ans.size() == 0)
                ans = sub;
            else 
                ans =  sub + " "+ ans;
            // again shift the i to first occurence of the char just after the space or it could be a next space 
            i = j+1;
        }
        return ans;
    }
};

// @lc code=end


int main(){
    Solution sol;
    string input="the sky is blue";
    string out;
    out=sol.reverseWords(input);
    cout<<out;
    return 0;
}