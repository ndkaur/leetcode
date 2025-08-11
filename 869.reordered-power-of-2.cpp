/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
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



class Solution {
public:
    string sorted(int n){
        string s = to_string(n);
        sort(s.begin(), s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string s = sorted(n);
        // check all powers of 2 , 2^30 will be of size more thn 10^9
        //1<<0 = 1 , 1<<1 = 10 ->2   , 1<<2 = 100 = 4
        for(int p=0; p<=29; p++){
            int powerof2 = (1<<p); 
            if(s==sorted(powerof2)){
                return true;
            }
        }
        return false;
    }
};





// generate all permutations -> O(n! * n)
// then  check for each permutation if pow of 2 or not ->O(log n)
//  
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        // convert n to string 
        string s = to_string(n);
        // make a vector from string t generate permutations 
        vector<int> nums(s.size());
        for(int i=0; i<s.size(); i++){
            nums[i] = s[i]-'0';
        }
        // we want to return only bool val so no  need to store the permuataions
        return permutation(0, nums);
    }

    bool permutation(int idx, vector<int>& nums){
        if(idx==nums.size()){
            // we need not to store the permutes just want a bool val 
            return isPow(nums);
        }
        for(int i=idx; i<nums.size(); i++){
            swap(nums[i], nums[idx]);
            //next iteration
            if(permutation(idx+1, nums))
                return true;
            // backtracking 
            swap(nums[i], nums[idx]);
        }
        return false;
    }

    bool isPow(vector<int>& nums){
        if(nums[0]==0)
            return false;
        //convert vector<int> into a integer val 
        // 1, 2, 3 ->123
        int numb = 0;
        for(int x:nums){ // getting a int val
           numb = numb * 10 + x;
        }
        // check if pow of 2 
        while(numb > 0 && (numb & 1)==0){
           numb = numb>>1;
        }
        return numb == 1;
    }
};


// we can count the freq of nums in both the numbers 
// o(logn)
// O(1)
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        // count of all the digits present in n
        vector<int> freq = count(n);
        // match the freq with all the pow of 2 
        for(int i=0 , powof2 = 1; i<30; i++, powof2 <<= 1){
            // if array of freq is eaxctly same as count of digits in pow of 2
            if(freq == count(powof2))
                return true;
        }
        return false;
    }   
    vector<int> count(int n){
        vector<int> ans(10);
        while(n>0){
            // 123 
            // rem = n%10 -> 3
            ans[n%10]++;
            n= n/10;
        }
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    int n= 1234;
    bool ans = sol.reorderedPowerOf2(n);
    cout<<ans;
    return 0;
}