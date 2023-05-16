/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
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
    int maxVowels(string s, int k) {
        int n= s.size();
        int mx=0;
        int curr=0;
        for(int i=0; i<n; i++){
            curr += isVowel(s[i]);
            if(i>=k){
                //removing the count if length exceeded the k and the previous char is also vowel 
                curr -= isVowel(s[i-k]);
            }
            mx = max(mx,curr);
        }
        return  mx;
    } 
    int isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            return 1;
        return 0;
    }
};
// @lc code=end


int main(){

    return 0;
}