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
        int n = nums.size();
        vector<int> left(n,1);
        vector<int> right(n,1);

        for(int i=1; i<n; i++){
            if(nums[i-1]<=nums[i]){
                left[i]= left[i-1]+1;
            }
        }

        for(int i=n-2; i>=0; i--){
            if(nums[i]<=nums[i+1]){
                right[i] = 1+right[i+1];
            }
        }

        // no filled the left and right so basically the max in left will be our answer + 1(as we change one elem)
        // but suppose mx = 4, and the len of nums is 4 , then we direclty 
        // add 4+1 hoping to change one elem , but we out of bounds so have to take min of len or mx
        int mx = *max_element(left.begin(), left.end());
        mx = min(n, mx+1);

        // now for any elem to be valid for replacement the elm prev must be samller to the next elem 
        for(int i=1; i<n-1; i++){
            if(nums[i-1]<=nums[i+1]){
                mx = max(mx, left[i-1]+1+right[i+1]);
            }
        }
        return mx;
    }
};


int main(){

    return 0;
}