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
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int lb = -1; // marks the position where the number greater then max found
        int mn = -1;
        int mx = -1;
        long long ans = 0;
        for(int i=0; i<n; i++){
            // num in the given intervals
            if(nums[i]>= minK && nums[i]<=maxK){
                // first occurence of min , its idx
                mn  = (nums[i] == minK) ? i : mn;
                // first occurence of max , its idx
                mx = (nums[i] == maxK) ? i : mx;
                // .. finding total value 
                ans += max(0, (min(mx, mn)-lb));
            }
            else{
                lb = i; // when any number out of range is found
                mn = -1;
                mx = -1;
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}