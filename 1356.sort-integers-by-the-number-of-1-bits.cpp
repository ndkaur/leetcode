/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
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
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
       
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i=0; i<n; i++){
            int cnt = cntbits(arr[i]);
            pq.push({cnt,arr[i]});
        }
        vector<int> ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    int cntbits(int num){
        int cnt =0;
        while(num){
            if(num & 1)
                cnt++;
            num = num>>1;
        }
        return cnt;
    }
};

// O(N∗log(N))
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
    static bool comp(int a, int b){
        int cnta =  cntbits(a);
        int cntb  = cntbits(b);
        if(cnta==cntb){
            return a<b;
        }
        return cnta<cntb;
    }
    static int cntbits(int num){
        int cnt =0;
        while(num){
            if(num & 1)
                cnt++;
            num = num>>1;
        }
        return cnt;
    }
};

// @lc code=end


int main(){

    return 0;
}