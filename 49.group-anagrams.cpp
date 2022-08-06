/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
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

//  map will store vector<string> in following way 
// s= eat  t= sort(s)= aet 
// sorted string is the key  , value is the original string
// key       value 
//  aet  -> eat ,tea, ate
//  ant->  tan, nat
// abt->  bat


class Solution { // o(n) + O(nlogn)
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        int n= str.size();
        unordered_map<string,vector<string>> mp;
        for(auto s:str){
            string t= s;
            sort(t.begin(),t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto itr:mp){
            ans.push_back(itr.second);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        int n= str.size();
        unordered_map<string,vector<string>> mp;
        for(auto s:str){
            mp[strSort(s)].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto itr:mp){
            ans.push_back(itr.second);
        }
        return ans;
    }
    string strSort(string s){
        vector<int> count(26,0);
        for(auto ch:s){
            count[ch-'a']++;
        }
        string t; 
        int j=0;
        while(j<26){
            if(count[j]==0)
                j++;
            else {
                t.push_back(j+'a');
                count[j]--;
            }
        }
        return t;
    }
};


// @lc code=end


int main(){

    return 0;
}