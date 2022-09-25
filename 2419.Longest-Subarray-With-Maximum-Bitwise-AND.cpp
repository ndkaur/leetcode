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
        int n= nums.size();
        int ele = *max_element(nums.begin(), nums.end());
        int cnt =0;
        int mxcnt =0;
        for(int i=0; i<n; i++){
            if(nums[i] == ele){
                cnt++;
                mxcnt = max(mxcnt, cnt);
            }
            else {
                cnt =0;
            }
        }
        return mxcnt;
    }
};

int main(){

    return 0;
}