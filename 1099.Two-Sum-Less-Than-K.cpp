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

class Solution0 {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = -1;
        for(int i=0; i<n; i++){
            int sum = nums[i];
            for(int j=i+1; j<n; j++){
                sum += nums[j];
                if(sum<k){
                    mx = max(mx, sum);
                }
                sum -= nums[j];
            }
        }
        return mx;
    }
};

class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = -1;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            int target = k-nums[i];
            // idx where target is found
            int j = find(nums, target, i+1, n-1);
            if(j!=-1)
                mx = max(mx, nums[i]+nums[j]);
        }
        return mx;
    }
    int find(vector<int>& nums, int target, int l, int r){
        int start = l;
        while(l<=r){
            int mid = l+(r-l)/2;
            // if found we want sum < k , if found exactly equal less will be on left side 
            if(nums[mid]==target || nums[mid]>target){
                r = mid-1;
            }
            else 
                l = mid+1;
        }
        return (r>=start) ? r : -1;
    }
};

int main(){

    return 0;
}