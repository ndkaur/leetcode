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

// same as finding permutations of an array with duplicates with the swap method

class Solution {
public:
    bool isPerfect(int num){
        int r = sqrt(num);
        return r*r==num;
    }

    void f(int idx, int& cnt, vector<int> nums){
        int n = nums.size();
        // reached end only when previous indexes were perfect squares sum 
        if(idx>=n){
            cnt++;
            return;
        }

        for(int i=idx; i<n; i++){
            // checkin for duplicates 
            if(i>idx && nums[i]==nums[idx])
                continue;
            // no duplicate we picking 0
            // create permutaion of array 
            swap(nums[idx],nums[i]); // finding permutations 
            // checking is perfect square or we dont hve a pair yet ie idx=0
            if(idx==0 || isPerfect(nums[idx-1]+nums[idx])){
                f(idx+1, cnt, nums);
            }
        }
    }
    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 0;
        f(0, cnt, nums);
        return cnt;
    }
};

int main(){

    return 0;
}