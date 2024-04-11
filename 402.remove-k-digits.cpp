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
        if(n==k)
            return "0";

        // monotonic increasing stack:- we want smaller elemts first rhen bigger elems and this order is increasing
        stack<char> stk;
        for(auto ch:num){
            // break condition will be decreasing 
            while(k && !stk.empty() && int(stk.top()) > (int)(ch)){
                stk.pop();
                k--;
            }
            stk.push(ch);
        }

        if(k){
            while(k--){
                stk.pop();
           }
        }
        
        // what if the num has leadin zeroes 
        // eg = 10200 k=1
        // stk = 1 , 1>0 pop 1 , k=0
        // stk= 0200  
        // we have a leading zero but its at the end of the stack 
        // to remove it we take help from another stack 
        stack<char> help;
        while(stk.size()){
            help.push(stk.top());
            stk.pop();
        }
        // stk = 0200  , help = 0020
        // remove trailing zeroes 
        while(help.top()=='0' && help.size()!=1){
            help.pop();
        }

        string ans = "";
        // now add the char to the final ans
        while(help.size()){
            ans.push_back(help.top());
            help.pop();
        }

        return ans;
    }
};

// 1432219

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