/*
 * @lc app=leetcode id=1387 lang=cpp
 *
 * [1387] Sort Integers by The Power Value
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
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
class Solution0 {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> power;
        for(int i=lo ;i<= hi;i++){
            power.push_back({find(i),i});
        }
        sort(power.begin(),power.end());
        return power[k-1].second;
    }
    int find(int num){
        int count=0;
        while(num!=1){
                if(num%2==0)
                    num =num/2;
                else
                    num= 3*num+1;
                count++;
        }
        return count;
    }
};


class Solution {
public:
    int getKth(int lo, int hi, int k) {
        
    }
};

// @lc code=end


int main(){
    Solution sol;
    int lo=12;
    int hi=15;
    int k = 2;
    int ans = sol.getKth(lo,hi,k);
    cout<<ans;
    return 0;
}