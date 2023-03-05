/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
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
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1)
            return 0;
        //   0   1  2   3   4   5  6  7 8  9
        // 100,-23,-23,404,100,23,23,23,3,404
        // 100 -> {0,4}
        // -23 -> {1,2}
        // 404 -> {3,9}
        // 23 -> {5,6,7}
        // 3 -> {8}
        // number and its repeated occurence 
        unordered_map<int,vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[arr[i]].push_back(i);
        }
        int cnt = 0;

        queue<int> q;
        vector<int> visited(n);
        q.push(0);
        visited[0] = 1;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node_idx = q.front();
                q.pop();

                if(node_idx == n-1) // reached last idx
                    return cnt;
                
                // indexes a node can visit are stored in map 
                // 0-> arr[0] = 100  so mp[100] = array 
                vector<int>& adjacent = mp[arr[node_idx]]; // same occurence
                // prev idx
                adjacent.push_back(node_idx-1);
                // next idx 
                adjacent.push_back(node_idx+1);

                for(auto itr:adjacent){
                    if(itr>=0 && itr<n && !visited[itr]){ // valid idx
                        q.push(itr);
                        visited[itr] = 1;
                    }
                }
                adjacent.clear();
            }
            cnt++;
        }
        return -1; //not reachable
    }
};
// @lc code=end


int main(){

    return 0;
}