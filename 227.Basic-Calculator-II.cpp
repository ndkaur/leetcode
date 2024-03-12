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
    int calculate(string s) {
        stack<int> stk;
        long long temp = 0;
        int ans = 0;
        char sign = '+';

        for(unsigned int i=0; i<s.size(); i++){
            if(isdigit(s[i])){ // nu can be double digit or more digit also 
                temp = temp*10 + s[i]-'0';
            }
            // when its a sign or we reached end 
            if(!isdigit(s[i]) && !isspace(s[i]) || i==s.size()-1){
                if(sign=='-'){
                    stk.push(-temp);
                }
                else if(sign=='+'){
                    stk.push(temp);
                }
                else{
                    int num;
                    if(sign=='*'){
                        num = stk.top()*temp;
                    }
                    else 
                        num = stk.top()/temp;
                    stk.pop();
                    stk.push(num);
                }
                sign = s[i];
                temp = 0;
            }
        }
        while(stk.size()){
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};



int main(){

    return 0;
}