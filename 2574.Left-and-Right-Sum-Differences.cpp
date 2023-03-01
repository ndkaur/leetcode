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


class Solution0 {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        int lsum = 0;
        vector<int> l(n,0);
        for(int i=1; i<n; i++){
            lsum += nums[i-1];
            l[i] = lsum;
        }
        vector<int> r(n,0);
        int rsum =0;
        for(int i=n-2; i>=0; i--){
            rsum += nums[i+1];
            r[i] =  rsum;
        }
       
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            ans[i] = abs(r[i]-l[i]);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int num:nums)
            total += num;
        int lsum=0;
        vector<int> ans;
        for(int i=0; i<n; i++){
            int rsum = total - (lsum+nums[i]);
            ans.push_back(abs(rsum-lsum));
            lsum += nums[i];
        }
        return ans;
    }
};



int main(){

    return 0;
}