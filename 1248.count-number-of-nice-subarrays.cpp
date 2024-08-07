/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 */
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

// @lc code=start

// prefix sum -> O(2n)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]%2==1)
                nums[i]=1;
            else 
                nums[i] = 0;
        }
        unordered_map<int,int> mp;
        int cnt =0;
        int sum =0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(sum==k)
                cnt++;
            // if remainginexist then only cnt++
            int rem = sum -k;
            cnt += mp[rem];

            mp[sum]++;
        }
        return cnt;
    }
};

// same as binary subarray with sum 930

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }
    int atmost(vector<int>& nums, int k){
        int n = nums.size();
        int l =0;
        int r =0;
        int cntodd =0;
        int ans =0;
        while(r<n){
            if(nums[r] % 2 !=0){
                cntodd++;
            }
            while(cntodd > k){
                if(nums[l] % 2!=0){
                    cntodd--;
                }
                l++;
            }
            ans += r-l +1;
            r++;
        }
        return ans;
    }
};




class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;

        int cnt = 0;  // sum of the odd cnt 
        int odd = 0; // cnt of the curr odd nums found
        int ans = 0; // final ans

        while(j<n){
            if(nums[j]%2!=0){ // its odd 
                odd++;
                cnt = 0; // the moment we find new odd num after satisfying k then new  subaary will begin 
            }

            while(odd==k){
                if(nums[i]%2==1){
                    odd--;
                }
                cnt++;
                i++;
            }
            ans += cnt; // in eg 3, after we visit first 1 then the remainging numbers will also make the subarray with the already counted nums
            j++;
        }
        return ans;
    }
};

// @lc code=end


int main(){

    return 0;
}