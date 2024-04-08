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

class Solution0 {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> stk;

        for(int i=0; i<n; i++){
            if(s[i]=='('){
                stk.push(i);
            }
            else if(s[i]==')'){
                if(stk.size()){
                    stk.pop();
                }
                else{
                    s[i]='#';
                }
            }
        }
        while(stk.size()){
            s[stk.top()]='#';
            stk.pop();
        }

        string ans = "";
        for(int i=0; i<n; i++){
            if(s[i]!='#'){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        // Step 1 : Iterate from start
        int count=0; 
        for(int i=0;i<n;++i){
            if(s[i]=='('){ // for open bracket
                ++count;
            }
            else if(s[i]==')'){ // for close bracket
                if(count==0){  // if no. of close brackets > no. of open brackets
                    s[i]='#';
                }
                else{
                    // if matching parentheses found decrease count
                    --count;
                }
            }
        }
        
        // Step 2 : Iterate from end
        count=0;
        for(int i=n-1;i>=0;--i){
            if(s[i]==')'){ // for close bracket
                ++count;
            }
            else if(s[i]=='('){ // for open bracket
                if(count==0){ // if no. of open brackets > no. of close brackets
                    s[i]='#';
                }
                else{
                    // if matching parentheses found decrease count
                    --count;
                }
            }
        }
        
        // Step 3 : Create "ans" by ignoring the special characters '#'
        string ans="";
        for(int i=0;i<n;++i){
            if(s[i]!='#'){ 
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}
