/*
 * @lc app=leetcode id=1496 lang=cpp
 *
 * [1496] Path Crossing
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
    bool isPathCrossing(string path) {
        int n = path.size();
        set<pair<int,int>> st;
        st.insert({0,0});
        int x =0;
        int y=0;
        for(auto p:path){
            if(p=='N')
                y++;
            else if(p=='S')
                y--;
            else if(p=='E')
                x++;
            else 
                x--;
            
            if(st.find({x,y})!=st.end())
                return true;
            else st.insert({x,y});
        }
        return false;
    }
};
// @lc code=end


int main(){

    return 0;
}