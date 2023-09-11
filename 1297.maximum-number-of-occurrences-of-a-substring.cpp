/*
 * @lc app=leetcode id=1297 lang=cpp
 *
 * [1297] Maximum Number of Occurrences of a Substring
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
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        map<char,int> mp;
        map<string,int> mp1;
        int i=0;
        int j =0;
        int cnt =0;
        int diff =0;
        
        while(j<n){
            if(mp[s[j]]==0)
                diff++;
            mp[s[j]]++;
            
           // invalid condition 
            while(diff > maxLetters || j-i+1 > maxSize){
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    diff--;
                i++;
            }
            // valid len>=minSize  and distinct chars also under maxchars
            while(diff <= maxLetters && j-i+1 >= minSize){
                string temp = s.substr(i, j-i+1);
                mp1[temp]++; // cnt of string 
               
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    diff--;
                i++;
            }
            j++;
        }

        for(auto itr:mp1){
            cnt =  max(cnt, itr.second);
        }
        return cnt;
    }
};

// @lc code=end


int main(){

    return 0;
}