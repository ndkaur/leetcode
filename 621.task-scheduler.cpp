/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
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
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> count;
        for(char t:tasks)  
            count[t]++;
        priority_queue<int> pq;
        for(auto c:count)
            pq.push(c.second);
        
        int result=0;
        while(!pq.empty()){
            int time=0;
            vector<int> tmp;
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){  
                    tmp.push_back(pq.top()-1);
                    pq.pop();
                    time++;
                }
            }
            for(auto t:tmp){
                if(t){ 
                    pq.push(t);
                }
            }
            result+=pq.empty() ? time : n+1;
        } 
        return result;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<char> tasks= {'A','A','A','A','A','A','B','C','D','E','F','G'};
    int n =2;
    int result=sol.leastInterval(tasks,n);
    cout<<result;
    return 0;
}