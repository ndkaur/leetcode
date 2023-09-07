/*
 * @lc app=leetcode id=1876 lang=cpp
 *
 * [1876] Substrings of Size Three with Distinct Characters
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
    int countGoodSubstrings(string s) {
        int n = s.size();
        int i=0;
        int j =0;
        int cnt= 0;
        map<char,int> mp;
        while(j<n){
            mp[s[j]]++;
            if((j-i+1)<3){
                j++;
            }
            else{
                if(mp.size()==3 && j-i+1==3)
                    cnt++;
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                i++;
                j++;
            } 
        }
        return cnt;
    }
};
// @lc code=end


int main(){

    return 0;
}