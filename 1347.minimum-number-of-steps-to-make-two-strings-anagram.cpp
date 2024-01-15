/*
 * @lc app=leetcode id=1347 lang=cpp
 *
 * [1347] Minimum Number of Steps to Make Two Strings Anagram
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


class Solution0 {
public:
    int minSteps(string s, string t) {
        int n = s.size();
        int m = t.size();
        map<char, int> mp1;
        for(auto ch:s){
            mp1[ch]++;
        }
        map<char,int> mp2;
        for(auto ch:t){
            mp2[ch]++;
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(mp2.find(s[i])!=mp2.end()){
                if(mp1[s[i]]==mp2[s[i]]){
                    continue;
                }
                else if(mp1[s[i]]>mp2[s[i]]){
                    cnt += mp1[s[i]]-mp2[s[i]];  
                }
                
                mp1[s[i]]=0; 
                mp2[s[i]] = 0;
            }
            else {
                cnt++;
            }
        }
        return cnt;
    }
};  
   

class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> cnt1(26,0);
        vector<int> cnt2(26,0);

        for(auto ch:s){
            cnt1[ch-'a']++;
        }
        for(auto ch:t){
            cnt2[ch-'a']++;
        }
        int cnt= 0;
        for(int i=0; i<26; i++){
            cnt+= abs(cnt1[i]-cnt2[i]);
        }
        return cnt/2;
    }
};  
   

// @lc code=end


int main(){

    return 0;
}