/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}
// @lc code=start

class Solution { // O(n) , space->O(N)
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size();
        stack<char> s1,s2;
        for(int i=0; i<n; i++){
            if(s[i]!='#')
                s1.push(s[i]);
            else if(s[i]=='#' && s1.size())
                s1.pop();
        }
        for(int i=0; i<t.size(); i++){
            if(t[i]!='#')
                s2.push(t[i]);
            else if(t[i]=='#' && s2.size()) 
                s2.pop();
        } 

        string ans1, ans2;
        while(s1.size()){
            ans1+= s1.top();
            s1.pop();
        }
        while(s2.size()){
            ans2+=s2.top();
            s2.pop();
        }
        return ans1==ans2;
    }
};

class Solution { //time ->O(N) space ->O(1)
public:
    bool backspaceCompare(string s, string t) {
        int ptr1 =0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='#'){
                ptr1--;
                // if # is at starting of the s then -ve idx can come
                ptr1 = max(0,ptr1);
            }
            else {
                s[ptr1]=s[i]; // swaping values 
                ptr1++;
            }
        }
        int ptr2 = 0;
        for(int i=0; i<t.size(); i++){
            if(t[i]=='#'){
                ptr2--;
                ptr2=  max(0, ptr2);
            }
            else {
                t[ptr2] = t[i];
                ptr2++;
            }
        }

        if(ptr1!=ptr2){
            return false;
        }
        else{
            for(int i=0; i<ptr1; i++){
                if(s[i]!=t[i])
                    return false;
            }
            return true;
        }
    }
};
// ab#c -> ac 
// ad#c-> ac

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string a,b;
        for(auto c:S) {
            if(c=='#'){
                if((int) a.size()){ //if size of a exist that means if it has elements
                    a.pop_back();
                }
            }
            else 
                a=a+c; // adding anything to string puts the element next to the other element it doesnot add
        }
        for(auto c:T){
            if(c=='#'){
                if((int) b.size()){
                    b.pop_back();
                }
            }
            else
                b=b+c;
        }
        return (a==b);
    }
};
// @lc code=end
int main(){
    Solution sol;
    string S="xywrmp";
    string T="xywrrmu#p";
    bool out=sol.backspaceCompare(S,T);
    cout<<out;
}