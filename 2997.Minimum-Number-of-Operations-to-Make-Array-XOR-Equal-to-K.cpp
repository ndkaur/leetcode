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



// k=1
//  10 ^ 01 = 11
//  01 ^ 11 = 10
//  11 ^ 10 = 01
// 100 ^ 001 = 101 = no of set bits  = 2 = ans
class Solution0 {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        for(int num:nums){
            k = k^num;
        }
        // count set bits in k 
        return __builtin_popcount(k);
    }
};

// another logic : -
//  to make 0 we know the property that a^a = 0 
// so if there are even cnt of bits of both zero or one than answer will be 0
// if the cnt of one or zero is odd then the resulting xor will be 1
// so for each num in nums we need to check each of its bits at idx = 0, 1, 2, 3.... and then check the same idx bit with bits of k , if both of them are equal then nothing , if unequal that means we need to change some bit that is operation++;
// 2 1 0  <- idx 
// 0 1 0
// 0 0 1
// 0 1 1
// 1 0 0 
//......... 
// 1 0 0    -> xor value for each seperate idx (idx=0 0^1^1^0 = 0)
//now compare it with the each bits of k  k =1 
//  k =    0 0 1
// val->   1 0 0
// check-> ! . !  -> so at two positons the bits with k are not same ans = 2


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<32; i++){
            int xorVal = 0;
            for(int num:nums){
                int mask = num & (1<<i); // check at that bit of particular idx 
                xorVal = xorVal^mask;
            }
            // check with the k bit at that same idx
            int kBitVal = k & (1<<i);
            if(kBitVal != xorVal)
                cnt++;
        }
        return cnt;
    }
};

int main(){

    return 0;
}