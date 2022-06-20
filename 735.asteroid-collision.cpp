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
// @lc code=end


int main(){

    return 0;
}