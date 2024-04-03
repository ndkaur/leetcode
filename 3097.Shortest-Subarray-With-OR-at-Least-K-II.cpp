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
    void performOrOperation(int num, int& orVal, vector<int>& bitCount){
        orVal = orVal|num;
        // seting all the set bits of the num 
        for(int bit=0; bit<32; bit++){
            bitCount[bit] += (num & (1<<bit)) ? 1:0;
        }
    }
    void nullifyOrOperation(int& orVal, int num, vector<int>& bitCount){
        for(int bit=0; bit<32; bit++){
            bitCount[bit] += (num & (1<<bit)) ? -1 :0;
            if(bitCount[bit]==0)
                orVal = orVal & (~(1<<bit));
        }
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        int orVal = 0;
        // storing the cnt of all set bits of each number 
        vector<int> bitCount(n,0);

        int i = 0;
        int j = 0;
        while(j<n){
            performOrOperation(nums[j], orVal, bitCount);
            // if(orVal<k)
            //     continue;
            while(i<=j && orVal>=k){
                nullifyOrOperation(orVal, nums[i], bitCount);
                ans = min(ans, j-i+1);
                i++;
            }
            j++;
        }
        return ans==INT_MAX ? -1:ans;
    }
};

int main(){
    Solution sol;
    vector<int> arr= {1,2};
    int k = 0;
    int ans = sol.minimumSubarrayLength(arr, k);
    cout<<ans;
    return 0;
}


// {2,1,8} k =10
// orval = 0 
// ans = max,
//  setbit array  
// 0 1 2 3 
// 0 0 0 0

// i=0, j=0 , orval= 2 = 10 , orval<k 
// setbit array  
// 0 1 2 3 
// 0 1 0 0   

// i=1, j=0 , orval = 2 | 1 = 3  , 3<10
// setbit array  
// 0 1 2 3 
// 1 2 0 0

// i=2 , j=0 , orval = 3 | 8 = 11 = 1011  
// setbit array  
// 0 1 2 3 
// 2 3 0 1
// ans = j-i+1 = 2-0+1 = 3


// orval = 11 >10 so move j ahead , slide the window
// for that we have to reverse the or operation 
// so if the num[j] has set bit at any index then reduce the cnt of set bits in bitarray
// and if any bit is zero from 0->32 bits then do  and of orval with !that bit 

// j=0 , i=2  nums[j] = 2 = 10
// setbit array  
// 0 1 2 3 
// 2 2 0 1 
// bit at 2idx is 0 so 1<<2 = 100 , ~100 = 011 
// orval & ~(1<<idx) = 1011  & 0011 =  11 = 3 
// orval = 3 

// now orval<k so not valid window and i reached end so ans = 3


