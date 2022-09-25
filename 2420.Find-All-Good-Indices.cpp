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

// good index -> decrease  point increase 
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> dec(n,1);
        vector<int> inc(n,1);
        
        // fill dec from front
        for(int i=1; i<n; i++){
            if(nums[i-1] >= nums[i]){
                dec[i] = 1+ dec[i-1];
            }
        }
        // fill incereasing from back 
        for(int i=n-2; i>=0; i--){
            if(nums[i] <= nums[i+1]){
                inc[i] = 1+ inc[i+1];
            }
        }

        vector<int> ans;
        // when both are in range of  k <= i < n - k
        for(int i=k; i<n-k; i++){
            if(inc[i+1]>=k && dec[i-1]>=k){ // zero based indexing so 1 ahead and behind 
                ans.push_back(i);
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}