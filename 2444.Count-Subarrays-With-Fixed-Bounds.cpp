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

// sliding window 
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;
        int i = -1;
        int j = 0;
        int prevMn  = -1;
        int prevMx = -1;

        while(j<n){
            if(nums[j]<minK || nums[j]>maxK){
                i=j;
            }
            if(nums[j]==minK){
                prevMn = j;
            }
            if(nums[j]==maxK){
                prevMx = j;
            }
            // we want no of subarrays so use i
            ans += max(0, min(prevMn, prevMx)-i);
            j++;
        }
        return ans;
    }
};


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

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        // all the nums in subaaray must be btween mink and maxk
        int mn = -1; // idx where mink was found
        int mx = -1; 
        int i = 0;
        int j = 0;
        long long cnt =0;
        while(j<n){
            // out of range then slide the window
            if(nums[j]<minK || nums[j]>maxK){
                mn = mx = -1;
                i = j+1;
            }
            if(nums[j]==minK)
                mn = j;
            if(nums[j]==maxK)
                mx = j;
            // max from 0 cause the idx can be -ve
            // cnt of aubarray = j-i+1  = 
            cnt += max(0 , min(mx, mn)-i+1);
            j++;
        }
        return cnt;
    }
};

int main(){

    return 0;
}