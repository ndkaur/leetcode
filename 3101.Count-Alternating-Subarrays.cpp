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
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int i = 0;
        int j = 0;
        int prev = -1;
        while(j<n){
            if(nums[j]==prev){
                i = j; 
            }
            ans += j-i+1;
            prev = nums[j];
            j++;
        }
        return ans;
    }
};


class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 1;
        vector<int> dp(n,0);
        dp[0] = 1;
        for(int i=1; i<n; i++){
            if(nums[i]!=nums[i-1]){
                dp[i] = dp[i-1]+1;
            }
            else {
                dp[i] = 1;
            }
            ans += dp[i];
        }
        return ans;
    }
};



int main(){

    return 0;
}