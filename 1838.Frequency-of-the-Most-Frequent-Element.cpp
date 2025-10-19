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



// so one by one we pass the nums and we tak l=0 , r= that idx passed and target is the value at that index. we find mid and from mid till the idx we check if its possible to make all nums same , if so then we move our range and one by one check and keep on adding the nums from the left ie shifting the r to mid-1;
class Solution {
public:
    int bs(vector<int>& nums, int idx, int target, int k, vector<long>& pref){
        int n = nums.size();
        int l = 0;
        int r = idx;
        int ans = idx;

        while(l<=r){
            int mid = l+(r-l)/2;
            // starting from mid till idx we have to make all elms inbetween as target
            // (no of elms in range * target) - (actual sum of elm in range) = no of operrations 
            // no of operations <k then valid 
            long no_of_elms = idx-mid+1;
            long req_sum = no_of_elms*target;
            long curr_sum = pref[idx]-pref[mid]+nums[mid];
            
            int no_of_ope = req_sum - curr_sum;
            if(no_of_ope<=k){ // valid 
                ans = mid; // from this mid till the idx we can make all nums same 
                r = mid-1; // can try more
            }   
            else 
                l = mid+1;
        }
        // where the mid is till the r that the no of elmts that can have same val and become max freq
        return idx-ans+1;
    }
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // logn

        // pref su btw 2 indexes
        vector<long> pref(n);
        pref[0]=nums[0];
        for(int i=1; i<n; i++){
            pref[i] = pref[i-1]+nums[i];
        }

        int mx = 0;
        for(int i=0; i<n; i++){ // o(n)
            mx = max(mx, bs(nums,i, nums[i],k, pref)); // logn
        }
        // time comp -> O(N)+ O(NlogN)
        // space -> pefix arr O(1)
        return mx;
    } 
};



class Solution { //O(N)
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // in binary search our conditon check was , we set target and check range 
        // (no_of_elms * target) - actual_sum_of_Range <= k  => valid condition
        //  no_of_elms * target - actual_sum_of_range > k => invalid conditon when we move the windoe 
        // (j-i+1) * nums[j] - accumulative_sum_till_nums[j] > k
        // (j-i+1) * nums[j] > sum+k
        int l = 0;
        int r = 0;
        long sum = 0;
        int mx = 1;
        while(r<n){
            sum +=  nums[r];
            // invalid move window 
            while(sum+k < (r-l+1)* (long)nums[r]){
                sum-=nums[l];
                l++;
            }
            mx = max(mx, r-l+1);
            r++;
        }
        return mx;
    }
};

// [1,2,4], k = 5   => 3
// [1,4,8,13], k = 5  => 2
// [3,9,6], k = 2   => 1

int main(){

    return 0;
}