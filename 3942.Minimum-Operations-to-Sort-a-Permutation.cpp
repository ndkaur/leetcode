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
    bool check_inc(vector<int>& nums, int& mn_idx, int n){
        // 45 3210 , 4-5 =1 , 3-2= 1, 2-1=0 but 5-3 =2 step change
        int i;
        for(i=mn_idx; i<mn_idx+n; i++){
            if(nums[(i+1)%n]-1 != nums[i%n])
                break;
        }
        // will only break when i+1 is the min lem itslef
        if((i+1)%n == mn_idx)
            return true;
        return false;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int mn_idx = -1;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                mn_idx=i;
            }
        }

        // find inc or dec
        bool is_inc = check_inc(nums, mn_idx,n);
        bool is_dec = false;

        if(!is_inc){
            // if not inc then its dec, and we reverese dec it will be inc
            // so then it will pass in check_inc function
            reverse(nums.begin(), nums.end());
            // we revrsed so min location will also change
            mn_idx = n-mn_idx-1;
            is_dec = check_inc(nums, mn_idx, n);
        }

        if(!is_inc && !is_dec){
            return -1;
        }

        int ans = n;
        if(is_inc){
            ans = min(mn_idx, 2+(n-mn_idx));
        }
        else{ // dec
            ans = min(1+mn_idx, 1+(n-mn_idx));
        }
        return ans;
    }
};

// roated sortedrarray then we can make it sorted 
// two patterns - inc inc or dec dec
// inc -inc  ->  
//  45 0123  here left side is small so we can rotate 2 time = 2 = min_idx
// 2345 01 left side is big 
//       reverse-> 105432,  rotate->054321 rotate-> 543210 reverse-> 012345 total 4 operation
// left side big -> 2 reverse + (no of rotations)
    //no of rotations-> n - min idx = 6-4=2


//  dec dec 
// 10 5432 -> left side small rotate min idx time-> 1 + min_idx
    // rotate= 054321,  rotate=543210, reverse= 012345
// 3210 54 -> left side big  -> 1 + (n- min_elm_idx)
    //  reverse = 45 0123  rotate= 501234  rotate= 012345 


    

int main(){

    return 0;
}