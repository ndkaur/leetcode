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
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        // standing ta curr num we need to finf minumin till behind it 
        vector<int> left(n, INT_MAX);
        int lmn = nums[0];
        for(int i=1; i<n; i++){
            lmn = min(lmn, nums[i-1]);
            left[i] = lmn;
        }

        vector<int> right(n, INT_MAX);
        int rmn = nums[n-1];
        for(int i=n-2; i>=0; i--){
            rmn = min(rmn, nums[i+1]);
            right[i] = rmn;
        }

        int sum =INT_MAX;
        for(int i=1; i<n-1; i++){ // i<j>k
            if(left[i]<nums[i] && right[i]<nums[i]){
                sum = min(sum, nums[i]+left[i]+right[i]);
            }
        }
        return sum==INT_MAX ? -1 : sum; 
    }
};

// 8 6 1 5 3
// m 8 6 1 1
// 1 1 5 3 m
// 1<5 and 3<5

int main(){

    return 0;
}