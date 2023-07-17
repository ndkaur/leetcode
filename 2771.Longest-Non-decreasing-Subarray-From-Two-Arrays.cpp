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
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int mx =0;
        if(n1==1)
            return 1;
        // 4 test case 
        // 1-> check nums1 = i-1 and i 
        // 2-> check nums2 = i-1 and i 
        // 3-> check nums1 i and nums2 i-1 
        // 4-> check nums1 i-1 and nums2 i
        int prev1 = 1;
        int prev2 = 1;
        for(int i=1; i<n1; i++){
            int cur1 = 1;
            int cur2 = 1;
            // if itself has inc order 
            if(nums1[i] >= nums1[i-1]){
                cur1 = max(cur1, prev1+1); // inc in len 
            }
            if(nums2[i] >= nums2[i-1]){
                cur2 = max(cur2, prev2+1);
            }
            // check with other other 
            if(nums1[i] >= nums2[i-1]){
                cur1 = max(cur1, prev2+1);
            }
            if(nums2[i] >= nums1[i-1]){
                cur2 = max(cur2, prev1+1);
            }
            mx = max(mx,max(cur1, cur2));
            prev1 = cur1;
            prev2 = cur2;
        }
        return mx;
    }
};

class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int mx = 1;
        if(n==1)
            return 1;
        // 4 test case 
        // 1-> check nums1 = i-1 and i 
        // 2-> check nums2 = i-1 and i 
        // 3-> check nums1 i and nums2 i-1 
        // 4-> check nums1 i-1 and nums2 i
        vector<vector<int>> dp(n+1, vector<int>(2,1));
        // 2 -> denotes if we have picked from arr1 or arr2 the prev element 

        for(int i=1; i<n; i++){
            int cur1 = 1;
            int cur2 = 1;
            // if itself has inc order 
            if(nums1[i] >= nums1[i-1]){
                dp[i][0] = dp[i-1][0]+1; // inc in len 
            }
            if(nums2[i] >= nums2[i-1]){
                dp[i][1] = dp[i-1][1]+1;
            }
            // check with other other 
            if(nums1[i] >= nums2[i-1]){
                dp[i][0] = max(dp[i][0], dp[i-1][1]+1);
            }
            if(nums2[i] >= nums1[i-1]){
                dp[i][1] = max(dp[i][1], dp[i-1][0]+1);
            }
        }
        for(int i=0; i<n; i++){
            mx = max(mx, max(dp[i][0], dp[i][1]));
        }
        return mx;
    }
};

int main(){

    return 0;
}