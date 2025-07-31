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


// time O(32*N) ->O(N)
// O(32) ->O(1)
class Solution { 
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int bits = mx==0 ? 0 : 1+log2(mx);

        vector<int> nearest_setbit(bits,n);
        vector<int> ans(n);

        for(int i=n-1; i>=0; i--){
            int near = i;
            for(int j=0; j<bits; j++){
                if(nums[i]&(1<<j)){// bet is set in itself
                    nearest_setbit[j]=i;
                }
                else if(nearest_setbit[j]!=n){ // bit is not set itself but is set at some other index , we check our array and find where we have previusly saved the set bit index
                    near = max(near, nearest_setbit[j]);
                }
            }
            ans[i] = near-i+1;
        }
        return ans;
    }
};

// 1 0 2 1 3
//
//  _ _ _

int main(){

    return 0;
}