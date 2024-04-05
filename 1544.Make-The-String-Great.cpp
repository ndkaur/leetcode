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
    string makeGood(string s) {
        int n = s.size();
        stack<char> stk;

        for(int i=0; i<n; i++){
            stk.push(s[i]);
            while(stk.size() && ((stk.top()==s[i+1]+32 || stk.top()==s[i+1]-32))){
                stk.pop();
                i++;
            }
        }

        string ans="";
        while(stk.size()){
            ans = stk.top()+ans;
            stk.pop();
        }
       
        return ans;
    }
};

class Solution {
public:
    string makeGood(string s){
        string ans;
        for(char c : s){
            if(ans.size() && (toupper(c)==toupper(ans.back())) && (c-ans.back()!=0)) {
                // we want one upper and lower , if both same then theri diff wil be 0
                ans.pop_back();
            } 
            else{
                ans.push_back(c);
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}