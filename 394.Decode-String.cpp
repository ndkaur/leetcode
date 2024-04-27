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


class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<char> stk;
        for(int i=0; i<n; i++){
            if(s[i]!=']')
                stk.push(s[i]);
            else{
                string cur_str = "";
                while(stk.top()!='['){
                    cur_str = stk.top()+cur_str;
                    stk.pop();
                }
                stk.pop(); 
                string num = "";
                while(stk.size() && isdigit(stk.top())){
                    num = stk.top() + num;
                    stk.pop();
                }
                int times = stoi(num);
                while(times--){
                    for(int i=0; i<cur_str.size(); i++){
                        stk.push(cur_str[i]);
                    }
                }
            }
        }
        s = "";
        while(stk.size()){
            s = stk.top()+s;
            stk.pop();
        }
        return s;
    }
};


int main(){

    return 0;
}