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
    bool check(int num, vector<int> &nums) { 
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= num) 
                return (nums.size() - i) == num;                
        }
        return false;
    }
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size() ; i++) { // O(N)
            if (check(i, nums)) return i; // O(N)
        }
        return -1;
    }
};

class Solution {
public:
    int solve(vector<int>& nums, int val){
        int cnt =0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>=val)
                cnt++;
        }
        return cnt;
    }
    int specialArray(vector<int>& nums) {
       int n = nums.size();
       int l =0;
       int r = 1000;
        while(l<=r){
            int mid = l+(r-l)/2;
            int cnt = solve(nums, mid);
            if(cnt==mid)
                return cnt;
            if(cnt>mid){
                l = mid+1;
            }
            else 
                r = mid-1;
        }
        return -1;
    }
};

int main(){

    return 0;
}