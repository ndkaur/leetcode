/*
 * @lc app=leetcode id=1763 lang=cpp
 *
 * [1763] Longest Nice Substring
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
    string longestNiceSubstring(string s) {
        int n = s.size();
        string ans;
        int mx = 0;
        map<char,int> mp;
        for(int i=0; i<n; i++){
            string temp ="";
            for(int j=i+1; j<n; j++){
                temp = s.substr(i, j-i+1);
                if(check(temp)){
                    if(temp.size()>mx){
                        mx = temp.size();
                        ans = temp;
                    }
                }
            }
        }
        return ans;
    }
    bool check(string s){
        int n = s.size();
        for(int i=0; i<n; i++){
            if(islower(s[i])){ // small case then find upper
                char big = toupper(s[i]);
                if(find(s.begin(), s.end(), big)==s.end()) // not found
                    return false;
            }
            else{ // upper char then find lower
                char small = tolower(s[i]);
                if(find(s.begin(), s.end(), small)==s.end()) //  not found
                    return false;
            }
        }
        return true;
    }
};

// @lc code=end


int main(){

    return 0;
}