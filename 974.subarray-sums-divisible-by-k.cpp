/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
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

// Input: nums = [4,5,0,-2,-3,1], k = 5
// find the number of times any particular remainder occur 
// ones any remainder occur more than one time add its count to answer 
//              4    5    0    -2    -3      1
// sum-> 0      4    9    9     7     4      5
// rem-> 0(1)  4(1) 4(2)  4(3)  2(1)  4(3)   0(1)
// now when cnt = 1 -> {5}
// when cnt = 2 -> {5,0} , {0}
// when cnt = 3 -> {5,0,-2,-3}, {-2,-3} , {0,-2,-3}
// when cnt = 1 -> {4,5,0,-2,-3,1}
// cnt = 1+2+3+1 = 7

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        // .. prefix sum then check if sum id divisible by k
        int sum =0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            nums[i]= sum;
        }
        int cnt =0;
        map<int,int> mp;
        for(int i=0; i<n; i++){
            if(nums[i]%k==0)
                cnt++;
            int remaining  = nums[i]%k;
            if(remaining <0) //  if starting elm is -ve
                remaining += k;
            cnt += mp[remaining];
            mp[remaining]++;
        }
        return cnt;
    }
};

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        map<int,int> mp;
        mp[0] = 1;
        int cnt = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            int rem = sum % k;
            if(rem < 0) // case like {-1,2,9} starting rem is -ve
                rem += k;
            if(mp[rem] > 0)
                cnt += mp[rem];
            mp[rem]++;
        }
        return cnt;
    }
};

// k= 2
// nums ->       -1 2 9 
// sum ->   0    -1 1 10 
//  rem -> 0(1)  

//  -1 % 2 = -1 so but if we take 2 * 1 = 2 then  -1 + 2 = 1 
// that means rem + k

// @lc code=end


int main(){

    return 0;
}