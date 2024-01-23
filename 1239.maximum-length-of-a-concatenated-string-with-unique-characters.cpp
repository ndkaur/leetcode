/*
 * @lc app=leetcode id=1239 lang=cpp
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
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
// class Solution {
// public:
//     int maxLength(vector<string>& arr) {
//         int n= arr.size();
//         if(n==1) return arr[0].size();
//         map<string,int> mp;
//         for(auto c:arr)
//             mp[c]= c.size();
//         priority_queue<int> pq;
//         for(auto itr=mp.begin();itr!=mp.end();itr++){
//             pq.push(itr->second);
//         }
//         int mx1=pq.top();
//         pq.pop();
//         int mx2= pq.top();
//         pq.pop();
//         int sum = mx1+mx2;
//         return sum;
    // } // it doesnt work, as we need the max possible lenght of string 
// }; // not just lenght of top two maximum strings 
// @lc code=end

class Solution {
public:
    void dfs(int idx, string path, vector<string>& arr, int& ans){
        int n = arr.size();
        if(isUniqueChars(path)){
            ans = max(ans, (int)path.size());
        }
        if(idx==n || !isUniqueChars(path)){
            return;
        }

        for(int i=idx; i<n; i++){
            dfs(i+1, path+arr[i], arr, ans);
        }
    }
    bool isUniqueChars(string& s){
        unordered_set<char> st;
        for(auto ch:s){
            if(st.count(ch))
                return false;
            st.insert(ch);
        }
        return true;
    }
    int maxLength(vector<string>& arr) {
        int ans = 0;
        dfs(0, "", arr, ans);
        return ans;
    }
};

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n= arr.size();
        string str="";
        int idx=0;
        return help(arr,str,0);
    }
    int help(vector<string>& arr, string str ,int idx){
        unordered_set<char> s(str.begin(),str.end());
        if(s.size()!= str.size())
            return 0;
        int len = str.size();
        for(int i=idx;i<arr.size();i++){
            len= max(len,help(arr,str+arr[i],i+1));
        }
        return len;
    }
};


int main(){
    Solution sol;
    vector<string> arr={"cha","r","act","ers"};
    int ans = sol.maxLength(arr);
    cout<<ans;
    return 0;
}