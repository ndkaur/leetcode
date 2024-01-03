/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
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
    vector<int> lexicalOrder(int n) {
        vector<int> ans; 
        vector<string> temp;
        for(int i=1; i<=n; i++){
            string ch = to_string(i);
            temp.push_back(ch);
        }
        sort(temp.begin(), temp.end());
        for(auto ch:temp){
            ans.push_back(stoi(ch));
        }
        return ans;
    }
};

// @lc code=end


int main(){

    return 0;
}