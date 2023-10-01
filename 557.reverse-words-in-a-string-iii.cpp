/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
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
    string reverseWords(string s) {
        int n = s.size();
        string temp="";
        int cnt =1; // for adding space
        int i=0;
        while(i<n){
            string word="";
            while(s[i]!=' ' && i<n){
                word += s[i];
                i++;
            }
            i++;
            reverse(word.begin(), word.end());
            if(cnt>1){
                temp+= ' ';
            }
            cnt++;
            temp += word ;
        } 
        return temp;
    }
};

// @lc code=end


int main(){

    return 0;
}