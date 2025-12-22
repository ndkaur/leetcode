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
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum = 0;
        for(auto& num:nums){
            sum+= num;
        }

        long long target = sum%p;
        if(target==0)
            return 0;
        // now we have to check if we can make or find any subaary whose sum
        // is equal to the rem if so then return the length

        unordered_map<int,int> mp; // value = sum%p, idx
        // curr-prev = rem 
        // prev = curr - rem
        // prev%p =  (curr-rem+p)%p // to handle if any neg add p
        int curr = 0;
        mp[0] = -1;
        
        int ans = n;
        for(int i=0; i<n; i++){
            curr = (curr+nums[i])%p;
            int remaining = (curr-target+p)%p;
            if(mp.find(remaining)!=mp.end()){ // found then take len 
                ans = min(ans, i-mp[remaining]);
            } 
            mp[curr] = i;
        }

        return ans == n ? -1 : ans;
    }
};

// 10/6 = 4
// 16/9 = 7 -> now see if we can make the sum of 7 
// 2 3 5  6
// 2 5 10 16
// subarray sum equal to 7 ?


int main(){

    return 0;
}