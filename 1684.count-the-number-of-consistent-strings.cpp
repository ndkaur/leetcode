/*
 * @lc app=leetcode id=1684 lang=cpp
 *
 * [1684] Count the Number of Consistent Strings
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
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n= words.size();
        unordered_map<char,bool> mp;
        for(char c:allowed){
            if(!mp[c])
                mp[c]=1;
        }
        int count=0;
        for(auto s:words){
            bool flag=1;
            for(auto c:s){
                if(mp.find(c) == mp.end()){ // char not found  
                    flag=0;
                    break;
                }
            }
            if(flag==1) count++;
        }
        return count;
        
    }
};
// @lc code=end


int main(){
    Solution sol;
    string allowed ="abc";
    vector<int> words={"a","b","c","ab","ac","bc","abc"};
    int ans= sol.countConsistentStrings(allowed, words);
    cout<<ans;
    return 0;
}