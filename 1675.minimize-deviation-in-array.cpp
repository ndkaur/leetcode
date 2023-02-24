/*
 * @lc app=leetcode id=1675 lang=cpp
 *
 * [1675] Minimize Deviation in Array
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

// even number must be divide by 2 
// odd number to be multiplied by 2 

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq; // max heap 
        int mn = INT_MAX;
        for(int num:nums){
            if(num%2 == 0){ // even number simply put in queue 
                pq.push(num);
                mn = min(mn,num);
            } 
            else{ // odd number multiply by 2 
                pq.push(num*2);
                mn = min(mn, num*2);
            } 
        }
        int ans = INT_MAX;
        while(pq.size()){
            int t = pq.top();
            pq.pop();
            ans = min(ans , t - mn); // deviation is odd - even 
            // if inbetween we encounter any odd number then break 
            if(t%2==1) //odd
                break;
            // min will also change 
            mn = min(mn, t/2);
            // addback even num 
            pq.push(t/2);
        }
        return ans;
    }
}; 

// @lc code=end


int main(){

    return 0;
}