/*
 * @lc app=leetcode id=1624 lang=cpp
 *
 * [1624] Largest Substring Between Two Equal Characters
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
    int maxLengthBetweenEqualCharacters(string s) {
        map<char,int> mp;
        int n = s.size();
        int mx = -1;
        for(int i=0; i<n; i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]] = i;
            }
            else{
                int dif = i-mp[s[i]]-1;
                mx = max(mx, dif);
            }
        }
        return mx;
    }
};

// @lc code=end


int main(){

    return 0;
}