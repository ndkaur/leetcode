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
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans=0;
        // all elements to the left must be smaller to k 
        for(int i=0; i<=n/2; i++){
            ans += max(0, nums[i]-k);
        }

        // all elmts to the right must be greater than k  
        for(int i=n/2; i<n; i++){
            ans += max(0, k-nums[i]);
        }
        return ans;
    }
};

// 2 5 5 6 8



int main(){

    return 0;
}