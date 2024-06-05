/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start




class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<int> hash1(26,0);
        vector<int> hash2(26,0);

        // chars of the first word count
        for(auto ch:words[0]){
            hash1[ch-'a']++;
        }
        
        for(int i=1; i<n; i++){
            for(auto ch:words[i]){
                hash2[ch-'a']++;
            }

            // b=1, e =1, l =2, a=1
            //roller , r = 0 in h1, 1 in h2 so take min = 0 
            // min cause we want common in all strings
            // b , a doent exist in roller so b= 0, a=0
            for(int i=0; i<26; i++){
                hash1[i] = min(hash1[i], hash2[i]);
                hash2[i] = 0;
            }
        }

        vector<string> ans;
        for(int i=0; i<26; i++){
            // e =1, l =2
            if(hash1[i]>0){
                int cnt = hash1[i];
                while(cnt--){
                    char ch = i+'a';
                    string s;
                    s = ch;
                    ans.push_back(s);
                }
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<string> output;
        vector<map<char,int>> counts;
        for(auto word: words){
            map<char,int> m;
            for(auto c: word){
                m[c]++;
            }
            counts.push_back(m);
        }
        // mc=min count
        for(auto c='a'; c<='z'; ++c){
            int mc = 1000;
            for(auto count: counts){
                mc = min(mc, count[c]);
            }
            for(int t=0; t<mc; ++t){
                output.push_back(string(1,c));
            }
        }
        return output;
    }
};



// @lc code=end
int main(){
    Solution sol;
    vector<string> A={"bella","label","roller"};
    vector<string> output=sol.commonChars(A);
    for(auto s: output){
        cout<<s<<" ";
    }
    return 0;
}