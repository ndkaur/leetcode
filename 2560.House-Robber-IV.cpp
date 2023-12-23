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
    int possiblyTakenHouses(int mid, vector<int>& nums){
        int taken = 0;
        int n= nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]<=mid){
                taken++;
                i++;
            }
            
        }
        return taken;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        int ans;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(possiblyTakenHouses(mid,nums)>=k){// atleast
                ans = mid; 
                r = mid-1; // check if possible in less than this current
            }
            else 
                l = mid+1;
        }
        return ans;
    }
};

int main(){

    return 0;
}