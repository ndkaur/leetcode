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
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int ans = 0;
        stack<int> stk;

        for(int i=0; i<n; i++){
            // decreasing break condition
            if(stk.size()>0 && stk.top()>=target[i]){
                ans += stk.top()-target[i];
                stk.pop();
            }
            stk.push(target[i]);
        }
        ans+=stk.top();
        return ans;
    }
};


class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int ans = 0;
        ans += target[0];
        for(int i=0; i<n-1; i++){
            if(target[i+1]> target[i])
                ans += target[i+1]-target[i];
        }
        return ans;
    }
};


// next smaller elm -> we wan to keep track of it 
// so whenevr we encounter a smaller elem than current elm then break 
// cuur elem on stack top > new elm in array 
// break consiton is decresing so stack will be monotnic  incresing




int main(){

    return 0;
}