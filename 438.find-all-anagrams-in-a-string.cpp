/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
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
    vector<int> findAnagrams(string s, string p) {
        // s = "cbaebabacd", p = "abc"
        int n = s.size();
        int m = p.size();
        vector<int> freq1(26,0);
        for(int i=0; i<m; i++){
            freq1[p[i]-'a']++;
        }
        vector<int> freq2(26,0);
        int i =0; 
        int j=0;
        vector<int> ans;
        while(j<n){
            freq2[s[j]-'a']++;
            if(j-i+1 == m){
                if(checkEqual(freq1, freq2)){
                    ans.push_back(i);
                }
            }
            if(j-i+1 < m){
                j++;
            }
            else{
                freq2[s[i]-'a']--;
                i++;
                j++;
            }
        }
        return ans;
    }
    bool checkEqual(vector<int>& a, vector<int>& b){
        for(int i=0; i<26; i++){
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
};
// @lc code=end


int main(){

    return 0;
}