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
        int n = deadends.size();
        unordered_set<string> st(deadends.begin(), deadends.end());
        unordered_set<string> visited;

        if(st.find("0000")!=st.end())
            return -1;
        visited.insert("0000");

        queue<string> q;
        q.push({"0000"});

        int cnt = 0;
        
        while(q.size()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto curr = q.front();
                q.pop();
                if(curr==target)
                    return cnt;
                vector<string> nebor = nebors(curr);
                for(auto ne:nebor){
                    if(visited.find(ne)!=visited.end())
                        continue;
                    if(st.find(ne)!=st.end())
                        continue;
                    // mark as visited
                    visited.insert(ne);
                    q.push(ne);
                }
            }
            cnt++;
        }
        return -1;
    }
    vector<string> nebors(string& curr){
        int n = curr.size();

        vector<string> ans;

        for(int i=0; i<4; i++){
            for(int diff=-1; diff<=1; diff+=2){
                string temp = curr;
                temp[i] = (temp[i]-'0' + diff + 10) % 10 + '0';
                ans.push_back(temp);
            }
        }
        return ans;
    }
};


class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dict(deadends.begin(), deadends.end());
        unordered_set<string> used;
        
        string st = "0000";
        if(dict.count(st))
            return -1;
        
        int cnt=0;
        queue<string> q;
        q.push(st);
        used.insert(st);
        
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                string curr = q.front();
                q.pop();
                
                if(curr == target)
                    return cnt;

                for(int i=0; i<4; i++) {
                    string tmp = curr;
                    
                    char ch = tmp[i];
                    int num = ch -'0';
                    int x = (num+11)%10, y=(num+9)%10;
                    
                    tmp[i] = x+'0';
                    if(!used.count(tmp) && !dict.count(tmp)) {
                        q.push(tmp);
                        used.insert(tmp);
                    }
                    
                    tmp[i] = y+'0';
                    if(!used.count(tmp) && !dict.count(tmp)) {
                        q.push(tmp);
                        used.insert(tmp);
                    }
                }
            }
            cnt++;
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