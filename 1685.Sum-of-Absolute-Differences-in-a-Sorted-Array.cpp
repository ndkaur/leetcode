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
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0]= nums[0];
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1]+nums[i];
        }

        vector<int> suf(n);
        suf[n-1]= nums[n-1];
        for(int i=n-2; i>=0; i--){
            suf[i] = suf[i+1] + nums[i];
        }

        vector<int> ans(n);
        for(int i=0; i<n; i++){
            ans[i] = ((nums[i]*i)-pre[i]) + (suf[i]-(nums[i]*(n-i-1)));
        }
        return ans;
    }
};

//     i
// 1,2,3,4,5
// (nums[i]-nums[0]) + (nums[i]-nums[1]) + (nums[i]-nums[2]) + (nums[i]-nums[i-1]) 
// + (nums[i]-nums[i]) + (nums[i+1]-nums[i]) + (nums[n-1]-nums[i])

// (nums[i]*i) - (nums[0]+nums[1]+nums[2]+nums[i-1]) 
// + (nums[i+1]+nums[n-1])- (nums[i])*(n-i-1)

// nums[i]*i - (prefix sum ) + (suffix sum) - (nums[i]* (n-i-1));



int main(){

    return 0;
}