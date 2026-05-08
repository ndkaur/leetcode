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



class Solution0 { // tle 
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> close(n,-1);
        close[0]= 1;
        close[n-1]= n-2;
        for(int i=1; i<=n-2; i++){
            int prev = abs(nums[i]-nums[i-1]);
            int next = abs(nums[i]-nums[i+1]);
            if(prev<=next){
                close[i]= i-1;
            }
            else {
                close[i]=i+1;
            }
        }
        vector<pair<int,int>> pref(n);
        pref[0] = {1,1};
        pref[n-1]  = {1,1};
        for(int i=1; i<=n-2; i++){
            int prev= 0;
            if(close[i]==i-1){
                prev =1;
            }
            else{
                prev = abs(nums[i]-nums[i-1]);
            }
            int next = 0;
            if(close[i]==i+1){
                next = 1;
            }
            else {
                next = abs(nums[i]-nums[i+1]);
            }
            pref[i] = {prev, next};
        }

        vector<int> res;
        for(auto q:queries){
            int start = q[0];
            int end = q[1];
            int ans = abs(nums[start]-nums[end]);
            int sum = 0;

            if(start<end){
                for(int i=start; i<end; i++){
                    sum+= pref[i].second;
                }
                ans = min(ans, sum);
            }
            else{
                for(int i=start; i>end; i--){
                    sum += pref[i].first;
                }
                ans = min(ans, sum);
            }
            res.push_back(ans);
        }
        
        return res;
    }
};


// can optimize in not storing closest but computing closest and pref sum on the go for both directions seperately

class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<long long> prev(n,0), next(n,0);
       
        // next = left to right
        // best case will be when next elm is the closest and cost is 1
        // for 0-> 1 is always closest 
        for(int i=0; i<n-1; i++){
            if(i==0 || nums[i]-nums[i-1] > nums[i+1]-nums[i]){ // left->right, best case ->next is closest
                next[i+1] = next[i]+1;
            }
            else{ // left->right, prev is closest , dir changed so cost=diff
                next[i+1] = next[i]+ nums[i+1]-nums[i];
            }
        }

        // prev = right->left
        // best case-> prev elm is the closest
        // i=0, prev = 0
        for(int i=1; i<n; i++){
            // i==n-1 -> n-2 is the closest always 
            // best case p<=n 
            if(i==n-1 || nums[i]-nums[i-1] <= nums[i+1]-nums[i]){
                prev[i]=prev[i-1]+1;
            }
            else{ // p>n , so closest is n, but still we have to go in right to left direction
                prev[i] = prev[i-1] + nums[i]-nums[i-1];
            }
        }

        
        vector<int> res;
        for(auto q:queries){
            int start = q[0];
            int end = q[1];
           
            if(start<end){
                res.push_back(next[end]-next[start]);
            }
            else{ // reverse n-1->0
                res.push_back(prev[start]-prev[end]);
            }

        }
        
        return res;
    }
};



int main(){

    return 0;
}