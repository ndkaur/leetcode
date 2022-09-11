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


// using min heap 
// pushing in heap -> [i][1] // max range 
// comparing with the [i][0] // min range 
// if both collide then see the res 

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n= intervals.size();
        sort(intervals.begin(), intervals.end());
        // min heap
        priority_queue<int,vector<int>, greater<int>> pq;
        // [i, j] -> i->j  and one interval can merge with other if last ele j is same 
        pq.push(intervals[0][1]);
        
        for(int i=1; i<n; i++){
            // [i, j]  if i come in that inetrval so all i+1 , i+2  will also merge 
            if(intervals[i][0]<= pq.top())// same intervals commom elemts
                pq.push(intervals[i][1]);
            else{ // different intervals
                pq.pop();
                pq.push(intervals[i][1]);
            }
        }
        return pq.size();
    }
};


// prefix sum method 
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n= intervals.size();
        vector<int> pre(10e5, 0);
        for(int i=0; i<n; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            pre[start] += 1;
            pre[end+1] -= 1;
        }
        int mx=0;
        for(int i=1;i<pre.size(); i++){
            pre[i] = pre[i]+pre[i-1];
            mx=max(mx, pre[i]);
        }
        return mx;
    }
};


int main(){

    return 0;
}