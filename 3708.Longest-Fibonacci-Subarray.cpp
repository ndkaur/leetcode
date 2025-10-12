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
    int longestSubarray(vector<int>& nums) {
       int n =  nums.size();
        if(n<=2)
            return n;
        vector<int> temp =nums;
        int mxLen = 2;
        int curr = 2;

        for(int i=2; i<n; i++){
            if(nums[i]==nums[i-1]+nums[i-2]){
                curr++;
            }
            else 
                curr=2;
            mxLen = max(mxLen, curr);
        }
        return mxLen;
    }
};


int main(){

    return 0;
}