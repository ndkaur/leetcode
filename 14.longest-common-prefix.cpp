/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
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
    string longestCommonPrefix(vector<string>& strs) {
        // find the len of min string among all 
        string small;
        int  mn= INT_MAX;
        for(int i=0; i<strs.size(); i++){
            if(strs[i].size() < mn){
                mn= strs[i].size();
                small = strs[i];
            }
        }

        int count=0;
        // checking the chars according to small string 
        for(int i=0; i<mn; i++){
            for(int j=0; j<strs.size(); j++){
                if(strs[j][i] != small[i])
                    return small.substr(0, count);
            }
            count++;
        }
        return small.substr(0,count);
    }
};

// we are checking for small string in all strings 
// flow-> i 
// j -> flower , flow, flight 
// count =0   check for ji
// 0,0   1,0   2,0
//  f     f     f   ->count=1
// 0,1   1,1   2,1
// l     l     l   -> count=2
// 0,2   1,2   2,2
// o     o     i    not match return the substr till that count 

// @lc code=end


int main(){

    return 0;
}