/*
 * @lc app=leetcode id=946 lang=cpp
 *
 * [946] Validate Stack Sequences
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

// pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
// pushed = [1,2,3,4,5], popped = [4,3,5,1,2]

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n= pushed.size();
        int m = popped.size();
        stack<int> stk;
        int i=0;
        for(int x:pushed){
            stk.push(x);
            while(stk.size() && stk.top()==popped[i]){
                stk.pop();
                i++;
            }
        }
        return stk.size()==0;
    }
};


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n= pushed.size();
        int m = popped.size();
        int i=0;
        int j=0;
        for(int x:pushed){
            pushed[i]=x;
            i++;
            while(i>0 && pushed[i-1] == popped[j]){
                i--;
                j++;
            }
        }
        return i==0;
    }
};
// @lc code=end


int main(){

    return 0;
}