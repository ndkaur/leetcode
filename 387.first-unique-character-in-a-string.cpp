/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
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
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        for(auto i:s)
            mp[i]++;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]==1)
                return i;
        }
        return -1;
    }
};
// @lc code=end


int main(){

    return 0;
}