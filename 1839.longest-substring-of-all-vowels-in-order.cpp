/*
 * @lc app=leetcode id=1839 lang=cpp
 *
 * [1839] Longest Substring Of All Vowels in Order
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
    int longestBeautifulSubstring(string word) {
        int n = word.size();
        int i=0;
        int j=0;
        int mx =0;
        map<char,int> mp;
        while(j<n){
            if(j>0 && word[j-1] > word[j]){
                i=j;
                mp.clear();
            }
            mp[word[j]]++;
            if(mp.size()==5)
                mx = max(mx, j-i+1);
            j++;
        }
        return mx;
    }
};
// @lc code=end


int main(){

    return 0;
}