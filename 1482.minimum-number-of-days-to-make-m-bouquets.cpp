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

// O((max(arr[])-min(arr[])+1) * N)
class Solution { // tle linear search 
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n < m*k)
            return -1;
        int mx = *max_element(bloomDay.begin(), bloomDay.end());
        int mn = *min_element(bloomDay.begin(), bloomDay.end());
        for(int i=mn; i<=mx; i++){ // linear search
            if(isPossible(bloomDay,m, k, i)){
                return i;
            }
        }
        return -1;
    }

    bool isPossible(vector<int>& bloom, int m, int k, int day){
        int  n=  bloom.size();
        int pick = 0;
        int bq = 0;
        for(int i=0; i<n; i++){
            if(bloom[i]<=day)
                pick++;
            else 
                pick = 0;
            if(pick>0 && pick==k){
                bq++;
                pick =0;
            }
        }
        return bq>=m;
    }
};

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

class Solution { //O(log(max(arr[])-min(arr[])+1) * N)
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = m* 1LL * k * 1LL;
        if(n < val)
            return -1;
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int l = *min_element(bloomDay.begin(), bloomDay.end());
    
        while(l<=r){
            int mid = l +(r-l)/2;
            if(isPossible(bloomDay,m, k, mid)==true){
                r = mid-1;
            }
            else 
                l = mid+1;
        }
        return l;
    }

    bool isPossible(vector<int>& bloom, int m, int k, int day){
        int  n=  bloom.size();
        int pick = 0;
        int bq = 0;
        for(int i=0; i<n; i++){
            if(bloom[i]<=day)
                pick++;
            else {
                bq += pick/k;
                pick =0;
            }
        }
        bq += pick/k;
        return bq>=m;
    }
};

class Solution {
public:
    bool isPossible(vector<int>&arr, int no_buq, int adj_flower, long long min_wait){
        int n = arr.size();
        long long pick_adj = 0; // size
        long long bq_made = 0; // cnt

        for(int i=0; i<n; i++){
            if(arr[i]<=min_wait){ // flower blooming
                pick_adj++;
            }
            else{
                pick_adj=0;
            }
            if(pick_adj==adj_flower){
                pick_adj=0;
                bq_made++;
            }
            if(bq_made==no_buq)
                return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n==0 || m==0 || k==0)
            return 0;
        long long val = m * 1ll * k * 1ll;
        if(val>n)
            return -1;

        long long l = *min_element(bloomDay.begin(), bloomDay.end()); // not possiblt 
        long long r = *max_element(bloomDay.begin(), bloomDay.end());
        
        while(l<=r){
            long long  mid = l+(r-l)/2;
            if(isPossible(bloomDay, m, k, mid)){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return (int)l;
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