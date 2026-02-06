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
    bool isPossible(long long k, vector<int>& nums){
        int n = nums.size();  
        long long cnt= 0;  
        for(int i=0; i<n; i++){
            int val = nums[i]/k;
            cnt+= val;
            if(nums[i]%k){
                cnt++;
            }
        }

        if(cnt<=k*k){
            return true;
        }
        return false;
    }
    int minimumK(vector<int>& nums) {
        int n = nums.size();
        long long l = 1;
        long long h = INT_MAX;
        int ans = 0;
       
        while(l<=h){
            long long mid = l+(h-l)/2;
            if(isPossible(mid, nums)){
                ans= mid;
                h = mid-1;
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