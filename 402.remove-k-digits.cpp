/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
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
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n == k)
            return "0"; 

        stack<char> stk; // monotonic increasing stack 
        stk.push(num[0]);
        for(int i=1; i<n; i++){
            while(!stk.empty() && k>0 && stk.top() > num[i]){
                stk.pop();
                k--;
            }
            // dont want to add 0 in the beginning+
            if(stk.empty() && num[i] == '0')
                continue;
            
            stk.push(num[i]);
        }
        // if after loop k still remaining 
        // when all elemnets are in increasing order  and no elem is removed so k not changed 
        // so remove first k elements
        while(!stk.empty() && k>0){
            stk.pop();
            k--;
        }
        if(stk.empty())
            return "0";
        string ans ="";
        while(stk.size()){
            ans+= stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// @lc code=end


int main(){

    return 0;
}