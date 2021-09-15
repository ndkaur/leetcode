/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
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
    int maxNumberOfBalloons(string text) {
        int n= text.size();
        unordered_map<char,int> mp;
        for(auto c:text)
            mp[c]++;
        return min({mp['b'],mp['a'],mp['l']/2,mp['o']/2,mp['n']});
        // l and o occur twice so we redue by dividing by 2
    }
};

// @lc code=end


int main(){
    Solution sol;
    string text="loonbalxballpoon";
    int ans = sol.maxNumberOfBalloons(text);
    cout<<ans;
   return 0;
}