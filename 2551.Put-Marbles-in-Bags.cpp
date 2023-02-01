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

// we have to put into bags 
// so we will make k -1 cuts in array 
// in each cut the boundary elemts will always be added 
// so lets say  we cut like k-1 
// a[0] .. a[i1]
//  a[i1+1] .... a[i2]
// a[i2+1] ... a[i3]
//  a[k+1] .... a[n-1]
// result will be  (a[0] + a[i1]) + (a[i2] + a[i3]) // boundary elemts


class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(k == 1 || n==k)
            return 0;
        vector<int> nums;
        for(int i=0; i<n-1; i++){
            nums.push_back(weights[i] + weights[i+1]);
        }

        sort(nums.begin(), nums.end());
        long long mn = 0;
        long long mx = 0;
        for(int i=0; i<k-1; i++){ // only k-1 cuts available 
            mn += nums[i];
            // size will decrese by 1 when made a new sum array from weights
            // to reach to corresponding boundary at the rigth side  use n-i
            // subtract 1 for 0 base indexing 
            // so n-i-1-1 = n-i-2
            mx += nums[n-i-2];
        }
        return mx - mn;
    }
};


int main(){

    return 0;
}