/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
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
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        find("","", 0, s, ans);
        return ans;
    }
    void find(string res, string curr, int idx, string& s, vector<string>& ans){
        int n = s.size();
        if(idx == n){
            if(curr.empty() && count(res.begin(), res.end(), '.') == 3)
                ans.push_back(res);
            return;
        }

        if(!curr.empty() && stoi(curr)== 0)
            return;
        
        curr.push_back(s[idx]);
        if(stoi(curr) > 255)
            return;
        find(res,curr, idx+1, s, ans);
        if(!res.empty()){ // if already had a value of res then add a . and add curr , make curr empty 
            find(res+"."+curr, "",idx+1, s,ans);
        }
        else{ // res empty so add curr as res , and make curr empty for next iteration 
            find(curr,"", idx+1,s,ans); 
        }
    }
};

// @lc code=end


int main(){

    return 0;
}