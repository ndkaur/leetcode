/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
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
    string mergeAlternately(string word1, string word2) {
        int n= word1.size();
        int m = word2.size();
        string ans;
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(i<n){
                ans+= word1[i];
                i++;
            }
            if(j<m){
                ans+=word2[j];
                j++;
            }
        }
        while(i<n){
            ans+= word1[i];
            i++;
        }
        while(j<m){
            ans+=word2[j];
            j++;
        }

        return ans;
    }
};
// @lc code=end


int main(){

    return 0;
}