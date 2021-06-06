/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadSet(deadends.begin(),deadends.end());
        unordered_set<string> visited;
        int result =0;
        if(deadSet.find("0000")!= deadSet.end())
            return -1;
        queue<string> wqueue;
        wqueue.push("0000");
        visited.insert("0000");
        while(!wqueue.empty()){
            int levelSize = wqueue.size();
            while(levelSize--){
                string up, down, curr = wqueue.front();
                wqueue.pop();
                if(curr== target) 
                    return result;
                for(int i=0;i<4;i++){
                    down =up=curr;
                    char upCh =up[i];
                    char downCh = down[i];
                    up[i] = (upCh == '9' ?'0': upCh+1);
                    down[i] = (downCh == '0' ? '9' :downCh-1);
                    if(visited.find(up)==visited.end() && deadSet.find(up)==deadSet.end()){
                        wqueue.push(up);
                        visited.insert(up);
                    }
                    if(visited.find(down)==visited.end() && deadSet.find(down)==deadSet.end()){
                        wqueue.push(down);
                        visited.insert(down);
                    }
                }
            }
            result++;
        }
        return -1;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    string target ="0202";
    int ans = sol.openLock(deadends,target);
    cout<<ans;
    return 0;
}