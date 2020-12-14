/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
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
    bool canReach(vector<int>& arr, int start) {
        int n= arr.size();
        //start = i from given position
        if(start>=0 && start<n && arr[start]>=0){
            if(arr[start]==0)
                return true;
        arr[start] = -arr[start]; // its visited 
        return (canReach(arr, start+arr[start] ) || canReach(arr,start-arr[start]) );
        }
        return false;
    }
};

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n= arr.size();
        if(arr[start]==0)
            return true;
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(start);
        visited[start]=true;
        while(!q.empty()){
            int curridx= q.front();
            q.pop();
            if(arr[curridx]==0)
                return true;
            int newidx = curridx+arr[curridx];
            if(newidx<n && visited[newidx] ==false){
                q.push(newidx);
                visited[newidx]=true;
            }
            newidx = curridx-arr[curridx];
            if(newidx >=0 && visited[newidx] ==false){
                q.push(newidx);
                visited[newidx]=true;
            }
        }
        return false;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<int> arr={4,2,3,0,3,1,2};
    int start=0;
    bool ans= sol.canReach(arr,start);
    cout<<ans;
    return 0;
}