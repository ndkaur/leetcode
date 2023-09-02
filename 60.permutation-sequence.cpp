/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
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

//  time limit exceeded
class Solution { //tle
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i=1; i<=n; i++){
            nums.push_back(i);
        }
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> freq(n,0);
        find(nums, temp, freq, ans);

        int sz=1;
        for(int i=1; i<=n; i++){
            sz = sz * i;
        }

        for(int i=0; i<sz; i++){
            if(i==k-1){
                temp = ans[i];
                break;
            }
        }

        string res="";
        for(int i:temp){
            res += to_string(i);
        }
        return res;
    }
    void find(vector<int>& nums, vector<int> temp, vector<int>& freq, vector<vector<int>>& ans){
        int n = nums.size();
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }

        for(int i=0; i<n; i++){
            if(!freq[i]){
                temp.push_back(nums[i]);
                freq[i]=1;
                find(nums, temp, freq, ans);
                freq[i] = 0;
                temp.pop_back();
            }
        }
    }
};




class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int fact =1;
        for(int i=1; i<=n; i++){
            nums.push_back(i);
            fact = fact *i;
        }
    
        string ans = "";
        int blockSize = fact/n; // 6/3 = 2 
        k = k-1; // zero base idxing 

        // 0 1 2
        // 1 2 3
        while(true){
            int idx = k/blockSize; // 2/2 =1 
            ans += to_string(nums[idx]); // ans = 2
            // remove that num from nums
            nums.erase(nums.begin()+idx); // nums= {1,3}
            if(nums.size()==0)
                break;
            // again chaning k for next iteration
            k = k % blockSize; // k = 2%2 = 0 
            blockSize = blockSize/ nums.size(); // 2/2 = 1
        }
        return ans;
    }
};

// n = 4
// k = 9
// fact = 1*2*3*4 = 24 
// block = 24/4 = 6  each num will have 6 permutations with it as starting num
// nums = {1,2,3,4}

// idx = k/block = 9/6 = 1 
// ans = 2  
// num = {1,3,4}
// update k => k%block = 9%6 =  3 
//  update block -> block/num.size = 6/3 = 2 

// k=3 , block =2
// nums= {1,3,4}
// idx = k/block = 3/2 = 1 
//  ans = 2+nums[1] = 23 
//  nums= {1,4}
// update k = k%block = 3%2 = 1
//  update block = block / size = 2/2 =1 

// k= 1 , block =1 
// num ={1,4}
// idx = k/block  = 1/1 = 1 
// ans = 23+nums[1]= 234 
//  nums ={1}
// k = 1%1 = 0
//  block = 1/1 =1 

// k =0 , block =1
//  nums= {1}
// idx = 0/1 = 0 
//  234 + nums[0] = 2341

// ans= 2341 




// @lc code=end


int main(){

    return 0;
}