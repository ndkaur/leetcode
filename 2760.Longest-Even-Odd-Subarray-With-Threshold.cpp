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
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int i =0;
        int j=INT_MAX;
        int ans=0;
        while(i<n){
            if(nums[i]>threshold || (i>0 && nums[i]%2==nums[i-1]%2)){
                ans = max(ans, i-j);
                j = INT_MAX;
            }
            if(nums[i]<=threshold && j==INT_MAX && nums[i]%2==0){
               j = i;
            }
            i++;
        }
        ans = max(ans,i-j);
        return ans;
    }
};

int main(){

    return 0;
}