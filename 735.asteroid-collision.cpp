/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
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
    vector<int> asteroidCollision(vector<int>& ast) {
        int n= ast.size();
        
        stack<int> st;
        for(int i=0;i<n;i++){
            if(ast[i]>0 || st.empty()){ // positve val of ast
                st.push(ast[i]);
            }
            else{ // negative val of ast 
                // ast val -ve , st.top= +ve  and st.top< abs(at val) 
                while(!st.empty() && st.top()>0 && st.top()< abs(ast[i])){
                    st.pop();
                }  
                //  st.top =8   ast[i]=-8 
                if(!st.empty() && st.top()== abs(ast[i])){
                    st.pop();
                }
                // st.top +ve , ast[i] -ve , st.top > abs(-ast[i]) then it is no need to push -ve val or pop +ve st.top 
                else{ 
                    if(st.empty() || st.top()<0){
                        st.push(ast[i]);
                    }
                }
            }
        }
        vector<int> ans(st.size());
        //  stack entries are in reverse order for vector entries 
        for(int i=(int)st.size()-1; i>=0; i--){
            ans[i]= st.top();
            st.pop();
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        // use basic stack idea 
        int n = ast.size();
        stack<int> stk;
        for(int i= 0; i<n; i++){
            // can addd in stack if empty or positive 
            if(stk.empty() || ast[i] > 0)
                stk.push(ast[i]);
            // stak not empty already have elements 
            else{
                // stk not empty and top elem is +ve and smaller then next elem
                while(!stk.empty() && stk.top() > 0 && stk.top() < abs(ast[i])){
                    stk.pop();
                }
                // stk not empty and top elem is +ve and equal to next elem
                if(!stk.empty() && stk.top() == abs(ast[i]))
                    stk.pop();
                // stk not empty and top ele is +ve and greater than next elem then
                // dont do anything cause no pop require 
                
                // stk not empty but later got empty or a negative number comes by
                else {
                    if(stk.empty() || stk.top()<0)
                        stk.push(ast[i]);
                }
            }
            
        }
        vector<int> ans(stk.size());
        for(int i=(int)stk.size()-1; i>=0; i--){
            ans[i] = stk.top();
            stk.pop();
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        vector<int> ans;
        for(int a:ast){
            bool dest = false; // is coming ast got destroyed or not 
            while(ans.size() && ans.back()>0 && a<0 && !dest){
                if(ans.back() >= abs(a)) // coming ast got destroyed
                    dest = true;
                if(ans.back() <= abs(a))
                    ans.pop_back();
            }
            if(!dest)
                ans.push_back(a);
        }
        return ans;
    }
};

// @lc code=end


int main(){

    return 0;
}