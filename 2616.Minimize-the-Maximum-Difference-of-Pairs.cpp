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

class Solution { //O(N*logN) log N (N = number of elements btw the min idx l and the max idx ro)
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n  = nums.size();
        sort(nums.begin(), nums.end());
        // we perform binary search on the difference
        int l = 0; // min diff can be 0 
        int r = nums.back()-nums.front(); // mx diff = last-first in sorted array
        int ans;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(isPossible(nums, p, mid)){
                ans = mid;
                // try finding min difference
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return ans; // return l;
    }
    bool isPossible(vector<int>& nums, int p, int diff){
        int n = nums.size();
        int cnt =0;
        // cnt = ()diff btw a pair) = no of pairs p
        for(int i=0; i<n-1;){
            if(nums[i+1]-nums[i]<=diff){
                cnt++;
                i+=2; // i, i+1 is calculatedas a pair
            }
            else 
                i++;
        }
        return cnt >= p;
    }
};

int main(){

    return 0;
}
