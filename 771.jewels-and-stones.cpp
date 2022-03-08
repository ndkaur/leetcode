/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
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
    int numJewelsInStones(string jewels, string stones) {
        int n= stones.size();
        map<char,int> mp;
        for(char x:jewels){
            mp[x]++;
        }
        int count=0;
        for( char c:stones){
            if(mp[c])
                count++;
        }
        return count;
    }
};
// @lc code=end


int main(){

    return 0;
}