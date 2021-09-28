/*
 * @lc app=leetcode id=929 lang=cpp
 *
 * [929] Unique Email Addresses
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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}

// @lc code=start
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int n= emails.size();
        unordered_set<string> s;
        for(string email:emails){
            string ans;
            for(char c:email){
                if(c=='+' || c=='@') break;
                if(c=='.') continue;
                ans+=c;
            }
            ans += email.substr(email.find('@'));
            s.insert(ans);
        }
        return s.size();
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<string> emails={"a@leetcode.com","b@leetcode.com","c@leetcode.com"};
    int ans = sol.numUniqueEmails(emails);
    cout<<ans;
   return 0;
}