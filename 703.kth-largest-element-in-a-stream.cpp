/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
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

// Complexity : Time - O(max(k, n)) for initialising k elements, 
// O((n-k)logk) for adding the rest ~ O( max(k, n) + nlogk - klogk), 
// Space - O(k)

class KthLargest {
public:
// pq is by default max heap 
    priority_queue<int,vector<int>, greater<int>> pq;  // making it min heap
    int size;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        // always keep priority queue size as k  
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            // the first ele can never be the kth largest as the size of k has increased the k
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val){
        pq.push(val);
        if(pq.size()>size) pq.pop();
        // the top most elemt is always the kth largest
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end


int main(){

    return 0;
}