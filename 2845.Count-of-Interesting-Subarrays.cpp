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
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long  n = nums.size();
        long long ans=0;
        // check if num % mod == k
        for(int i=0; i<n; i++){
            if(nums[i]%modulo==k)
                nums[i] =1;
            else 
                nums[i] =0;
        }
        // now check if cnt% mod == k  or if it is possible to make that count 
        // use like prefix sum technique 
        // if that cnt sum not found , then try finding its difference 
        unordered_map<long long, long long> mp;
        long long sum =0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            int mod_val =  sum%modulo;
            if(mod_val == k)
                ans++;
            // we not using else loop cause if this current idx not possible 
            // but what if the prev idx was possible and we can take it also 
            // and the current also 
            int remaining = mod_val -k;
            if(remaining<0)
                remaining += modulo;
            
            ans += mp[remaining];
            mp[mod_val]++;
        }
        return ans;
    }
};

int main(){

    return 0;
}