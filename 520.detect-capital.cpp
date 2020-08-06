/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
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
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start

// @lc code=end

//  A -65  Z= 90 
//  a= 97  z=122
// Z- capital char = +ve result
// Z - lower case letter = -ve result;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitalCount = 0;
        for(char c : word){
            if('Z' - c >= 0)
                capitalCount++; 
        }
        return (capitalCount == word.size() || (!capitalCount) || (capitalCount == 1 && 'Z' - word[0] >= 0));
                // all capital                 // all lower case        //  only starting letter is capital
           
    }
};


int main(){
    Solution sol;
    string word="FlaG";
    bool out=sol.detectCapitalUse(word);
    cout<<out;
    return 0;
}