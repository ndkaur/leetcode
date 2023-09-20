/*
 * @lc app=leetcode id=1658 lang=cpp
 *
 * [1658] Minimum Operations to Reduce X to Zero
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

class Solution0 { // O(n) , O(n)
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int mn = n+1; // remove all the numbers
        unordered_map<int,int> mp;
        
        int psum = 0; // prefix sum
        for(int i=0; i<n; i++){
            psum += nums[i];
            if(psum==x){
                mn = i+1; // 0 base indexing and we need nums to remove
            }
            if(psum > x)
                break;
            mp[psum] = i+1;
        }
        
        int ssum =0; // suffix sum
        for(int i=n-1; i>=0; i--){
            ssum += nums[i];
            if(ssum==x)
                mn = min(mn, n-i);// no of elemts to remove from back = n-1
            else if(ssum < x){
                int req = x - ssum;
                if(mp.find(req)!=mp.end()){ // the req elem is found
                    mn = min(mn, n-i + mp[req]);
                }
            }
            else  // ssum > x
                break;
        }
        return (mn != n+1) ? mn : -1;
    }
};


class Solution { // O(n) , O(1)
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int tsum =0;
        for(int num:nums){
            tsum+= num;
        }
        if(tsum < x)
            return -1;
        if(tsum == x)
            return n; // remove all elements
        int i = 0;
        int j = 0;
        int mx =0;

        int req = tsum - x;
        // now the ques changes to find subarray with sum = req
        int sum =0;
        while(j<n){
            sum += nums[j];
            while(sum > req){
                sum -= nums[i];
                i++;
            }
            if(sum == req)
                mx = max(mx, j-i+1);
            j++;
        }
        // ans will be = total len - req sum window len 
        return (mx!=0) ? n-mx :-1;
    }
};

// @lc code=end


int main(){

    return 0;
}