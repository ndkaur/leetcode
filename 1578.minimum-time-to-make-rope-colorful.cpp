/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * [1578] Minimum Time to Make Rope Colorful
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
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int m = neededTime.size();
        // we remove the min val of the two repeating chars 
        // to remove the min val we need the running max val of those same repeating characters
        int totalTime = 0; // store the min value ans
        int curTime = 0; // store the max running value
        for(int i=0; i<n; i++){
            // doesnot match 
            if(i>0 && colors[i] != colors[i-1]){
                curTime = 0;
            }
            // if match  -> min(prevmax, cur value of time in array )
            totalTime += min(curTime , neededTime[i]);
            curTime = max(curTime , neededTime[i]);
        }
        return totalTime;
    }
};


// using stack 

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int m = neededTime.size();
        int totalTime = 0;
        // we store the indexes
        stack<int> stk; 
        
        for(int i=0; i<n; i++){
            // alredy have stuff in stack so compare the chars if equal
            if(!stk.empty() && colors[stk.top()] ==  colors[i]){
                // we add the min val to the ans 
                if(neededTime[stk.top()] < neededTime[i]){
                    totalTime += neededTime[stk.top()];
                    stk.pop();
                    stk.push(i);
                }
                else{ // stk .top val isnt min then 
                    totalTime += neededTime[i];
                }   
            }
            else{
                stk.push(i);
            }
        }
        return totalTime;
    }
};


class Solution {
public:
    struct node{
        char c;
        int val;
    };
    
    int minCost(string s, vector<int>& cost) {
        stack<node> stack;
        int n=s.size(), result=0;
        
        for(int i=0; i<n; i++){
            if(!stack.empty() && stack.top().c==s[i]){
                if(stack.top().val<cost[i]){
                    result+=stack.top().val;
                    stack.pop();
                    stack.push({s[i], cost[i]});
                }
                else{
                    result+=cost[i];
                }
            }
            else{
                stack.push({s[i], cost[i]});
            }
        }
        
        return result;
    }
};
// @lc code=end


int main(){

    return 0;
}