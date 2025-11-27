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
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        // somehing like kaden and refix sum combination
        // for any k , remainder will be 0, 1, 2... k-1 then again 0 ...
        // eg= k = 2, rem = 0, 1, 0, 1 
        // so if we start storing  the prefix sum for each remainder this way length will be stored for each index 
        // and alongside if we maintian a prefixsum so to find prefsum between range
        // i->j = pref[j]-pref[i-1] 
        // here we take the curr pref for rem 0 and the previous stored value for rem 0         
        // ans = max(ans, pref[j]-pref[i-1]) , we want ans to be max, and pref[j]-pref[i-1] to me as min as possible 
        long long ans = -1e18;
        long long pref = 0; // running pref sum     
        vector<long long> prefSumForRem(k, 1e18);
        prefSumForRem[k-1]=0;

        for(int i=0; i<n; i++){
            pref += nums[i];
            // pref[i->prevrem] = pref(curr) - prefarra[pevrem prefsum]
            ans = max(ans, pref-prefSumForRem[i%k]);
            // update new min value 
            prefSumForRem[i%k] = min(prefSumForRem[i%k], pref);
        }
        return ans;
    }
};


int main(){

    return 0;
}