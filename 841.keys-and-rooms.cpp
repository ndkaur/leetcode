/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
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

//DFS
// complexity o(n)   space o(n)
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n= rooms.size();
        vector<bool> visited(n,0); // n is size , 0 is false 
        dfs(rooms,visited,0);
        for(int v:visited){ 
            if(!v)  // if the room is 0 // open 
                return false;
        }
        return true;
    }
    void dfs(vector<vector<int>> &adjroom,vector<bool> &visited,int room){
        visited[room]=true; // initilized the bool as true // so the search continues 
        for(int r:adjroom[room]){ // for room :room if the room is not visited then dfs
            if(!visited[r])
                dfs(adjroom,visited,r);
        }
    }
};

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n= rooms.size();
        queue<int> q;
        vector<bool> visited(n,0) // it false at first
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int room = q.front();
            q.pop();
            for(int r:rooms[room]){
                if(!visited[r]){
                    visited[r]=true;
                    q.push(r);
                }
            }
        }
        for(auto v:visited){
            if(!v)
                return false;
        }
        return true;
    }
};
// @lc code=end


int main(){

    return 0;
}