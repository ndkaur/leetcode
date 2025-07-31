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


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int mxelm = *max_element(nums.begin(), nums.end());
        int ans = 1;
        int mx = ans;
        for(int i=0; i<n; i++){
            if(nums[i]==mxelm){
                while(i+1<n && nums[i]==nums[i+1]){
                    ans++;
                    i++;
                }
                mx= max(mx, ans);
                ans=1;
            }
        }
        return mx;
    }
};

// a testcase can occur where {1,2,3,3,3,4,5,3,3,3,3,3} 
// mx el is 3, and ans will be 5 
// so the maxelem can occur at different indexes but the ma len will be that with more continus numbers 

int main(){

    return 0;
}