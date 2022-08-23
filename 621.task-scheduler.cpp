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

// (no of groups) * (no of elem in each group)+ (no with highest freq)
// (highest fre-1) * ( n+1) + (high fre no of elem)
//  A->3  B->4   high freq =4  n=2
// B A _ B A _ B A _ B
//  groups start from B end at B  = 2  = freq-1
//  no of elem in each group = depends on n  , n+1 spcae we have to give for char to repeat again

class Solution { //O(n)
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sz= tasks.size();
        int mx=0;
        unordered_map<char,int> mp;
        for(auto task:tasks){
            mp[task]++;
            mx = max(mx, mp[task]);
        }
        int ans = (mx -1) * (n+1);
        for(auto itr:mp){
            if(itr.second == mx)
                ans++;
        }
        return max((int)sz, ans);
    }
};

// Time Complexity:- O(nlogn)
// Space Complexity:- O(n)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // make a map to store the freq of each elem
        unordered_map<char,int> mp;
        for(auto task:tasks){
            mp[task]++;
        }
        //  make a max heap to store the freq 
        priority_queue<int> pq;
        for(auto itr:mp){
            pq.push(itr.second); // only count matter to us not the char 
        }
        int ans =0;
        while(!pq.empty()){
            int time = 0; // time in between 
            vector<int> temp; // to store the remaining freq of elem
            //  we cant repeat the same char until n
            for(int i=0;i<=n;i++){
                if(pq.size()){
                    temp.push_back(pq.top()-1); // reduce the current freq 
                    pq.pop();
                    time += 1;
                }
            }
            // insert back the remaining elem in the pq from arr
            for(int t:temp){
                if(t>0)
                    pq.push(t);
            }
            // calculate the ans 
            if(pq.empty()){
                ans += time;
            }
            else{
                ans += n+1; // time after which one char can repeat
            }
        }
        return ans;
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