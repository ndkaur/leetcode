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

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,vector<int>> mp; // num ->{indexes at which it occurs }
        vector<long long> pre(n);
        pre[0] = nums[0];
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1]+nums[i];
        }
        
        long long mx =LONG_MIN;
        long long ans;
        bool found =false;
        
        // there are negative numbers also so 
        // ele = 1 and k = 2
        // end1 = 1 + 2 = 3 , num+k
        // end2 = 1 - 2 = -1 , num-k

        for(int i=0; i<n; i++){
            if(mp.find(nums[i]-k)!=mp.end()){ // found
                found = true;
                for(auto itr:mp[nums[i]-k]){
                    // sum of those elemts between those indexes is the sum as ans
                    if(itr==0) // if its occuring at idx 0 so directly use that prefix sum 
                        ans = pre[i];
                    else // but if idx not =0 then there can be some other nums between the chosen indexes
                        ans = pre[i]-pre[itr-1]; // so the i will be the curr idx , j will be the stored idx in mp of the found num
                    mx = max(mx, ans);
                }
            }
            if(mp.find(nums[i]+k)!=mp.end()){
                found= true;
                for(auto itr:mp[nums[i]+k]){
                    if(itr==0)
                        ans= pre[i];
                    else 
                        ans = pre[i]-pre[itr-1];
                    mx = max(mx, ans);
                }
            }
            mp[nums[i]].push_back(i);
        }
        return found ? mx:0;
    }
};

int main(){

    return 0;
}