/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
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
class Solution { // tle  O(N^2)
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n= temp.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n; j++){
                if(temp[j]>temp[i] && !ans[i])
                    ans[i]= j-i;
            }
        }
        return ans;
    }
};

// monotonic decreasing stack 
class Solution { //O(n) O(n)
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n= temp.size();
        vector<int> ans(n);
        stack<int> stk;
        // we are storing the indexes in the stack 
        for(int i=0;i<n;i++){
            // store idx 
            while(stk.size() && temp[stk.top()] < temp[i]){ // increaing order  found so pop
                ans[stk.top()] = i- stk.top(); // i - stk idx 
                stk.pop();
            }
            // if decreasing order is maintianed 
            stk.push(i);
        }
        return ans;
    }
};



// @lc code=end


int main(){

    return 0;
}