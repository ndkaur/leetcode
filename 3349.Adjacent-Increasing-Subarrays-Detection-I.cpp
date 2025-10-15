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
    bool isinc(vector<int>& nums, int start, int k){
        for(int i=start; i<start+k-1; i++){
            if(nums[i]>=nums[i+1])
                return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<2*k)
            return false;
        for(int i=0; i<=n-2*k; i++){
            if(isinc(nums, i, k) && isinc(nums, i+k, k)){
                return true;
            }
        }
        return false;
    }
};


class Solution1 { // O(n^2)
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0; i<=n-2*k; i++){
            // n-*k , as we keeping the reming k elemts for 2nd subarray
            bool flag = true;
            for(int j=i+1; j<i+k; j++){
                if(nums[j-1] >=nums[j]){
                    flag = false;
                    break;
                }
            }

            if(flag==false)
                continue;
            
            for(int j=i+k+1; j<i+2*k; j++){
                if(nums[j-1]>=nums[j]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                return true;
        }
        return false;
    }
};


// one easy approcah is keep a cnt array of all increasing values and then check ont hat cnt array 
class Solution {//O(N)
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>cnt(n+1,1);
        for(int i=1; i<n; i++){
            if(nums[i-1]<nums[i]){
                cnt[i+1] = cnt[i]+1;
            }
        }
        
        for(int i=k; i<=n-k; i++){
            if(cnt[i]>=k && cnt[i+k]>=k)
                return true;
        }
        return false;
    }
};
int main(){

    return 0;
}