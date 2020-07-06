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