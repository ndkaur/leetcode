/*
 * @lc app=leetcode id=1647 lang=cpp
 *
 * [1647] Minimum Deletions to Make Character Frequencies Unique
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
    int minDeletions(string s) {
        int n = s.size();
        map<char,int> mp;
        for(auto ch:s){
            mp[ch]++;
        }
        int cnt =0;
        set<int> freq;
        for(auto itr:mp){
            if(freq.find(itr.second)==freq.end()){
                freq.insert(itr.second);
            }
            else{
                while(freq.find(itr.second)!=freq.end()){
                    cnt++;
                    itr.second--;
                }
                if(itr.second>0){
                    freq.insert(itr.second);
                }
            }
        }
        return cnt;
    }
};

// @lc code=end


int main(){

    return 0;
}