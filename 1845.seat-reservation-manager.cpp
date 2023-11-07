/*
 * @lc app=leetcode id=1845 lang=cpp
 *
 * [1845] Seat Reservation Manager
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
class SeatManager { 
public: 
    priority_queue<int, vector<int>, greater<int>> pq;
    SeatManager(int n) { // o(nlogn)  
        for(int i=1; i<=n; i++){
            pq.push(i);
        }
    }
    
    int reserve() { //O(logn)
        int ans = 0;
        if(pq.size()){
            ans = pq.top();
            pq.pop();
        }
        return ans>0 ? ans : -1;
    }
    
    void unreserve(int seatNumber) { //O(logn)
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
// @lc code=end


int main(){

    return 0;
}