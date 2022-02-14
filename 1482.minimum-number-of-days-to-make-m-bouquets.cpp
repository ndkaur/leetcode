/*
 * @lc app=leetcode id=1482 lang=cpp
 *
 * [1482] Minimum Number of Days to Make m Bouquets
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
class Solution0 { // time limit exceeded
public:
    int minDays(vector<int>& day, int m, int k) {
        int n= day.size();
        if(n<m*k) return -1;
        int l= *min_element(day.begin(),day.end());
        int h= *max_element(day.begin(),day.end());
        int pick=0;
        int bmade=0;
        while(l<=h){
            int mid= l+(h-l)/2;
            for(int i=0;i<n;i++){
                if(day[i]<=mid){
                    pick++;
                }else
                    pick=0;
                
                if(pick==k){
                    bmade++;
                    pick=0;
                }
            }
            if(bmade<m){
                l=mid+1;
            }else {
                h=mid;
            }
        }
        return l;
    }
};

class Solution {
public:
    int minDays(vector<int>& day, int m, int k) {
        int n= day.size();
        if(n< m*k) return -1;
        int l= *min_element(day.begin(),day.end());
        int h= *max_element(day.begin(),day.end());
    
        while(l<=h){
            int mid= l+(h-l)/2;
            if(possible(day,m,k,mid)==true){
                h= mid-1;
            }else{
                l= mid+1;
            }
        }
        return l;
    }

    bool possible(vector<int>&day, int m,int k,int mid){
        int n= day.size();
        int pick=0;
        int bmade=0;
        for(int i=0;i<n;i++){
            if(day[i]<=mid){
                pick++;
            }
            else 
                pick=0;
            if(pick>0){
                if(pick==k){
                    bmade++;
                    pick=0;
                }
            }
        }
        return (bmade>=m);
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<int> day={1,10,3,10,2};
    int m=3;
    int k=1;
    int ans = sol.minDays(day,m,k);
    cout<<ans;
    return 0;
}