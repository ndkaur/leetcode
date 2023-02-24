/*
 * @lc app=leetcode id=502 lang=cpp
 *
 * [502] IPO
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
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> projects; // capital, profit
        for(int i=0; i<n; i++){
            projects.push_back({capital[i], profits[i]});
        }
        // sort acc to min capital first
        sort(projects.begin(), projects.end());
        
        // max heap to store max profit on top
        priority_queue<int> pq;
        int i = 0;
        while(k--){
            // check if w <= capital
            while(i<n && projects[i].first <= w){ // if same capitals then on top will be max profit
                pq.push(projects[i].second); // push the profit
                i++;
            }
            if(pq.empty())
                break;
            // if we have values in pq then update the w and the profit 
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};
// @lc code=end


int main(){

    return 0;
}