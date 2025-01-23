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
    int minimizeXor(int num1, int num2) {
        int setbits = __builtin_popcount(num2);
        int ans = 0;

        // canceling the setbits from highest to lowest bits
        for(int i=31; i>=0 && setbits; i--){
            if(num1 & (1<<i)){
                setbits--;
                ans += (1<<i);
            }
        }
        // eg setbits = 3 , nums1 has 2 set bits that are canceled out 
        // 1 set bit count is remaing so to adjust it we will set one more bit in answer4

        // seting the bits from lowest to highest if the setbits cnt is remaining
        for(int i=0; i<32 && setbits; i++){
            // if the current bit is already set in nums1 that means we have 
            // already canceled it out and added it in answer
            if((num1 & (1<<i))==0){
                setbits--;
                ans += (1<<i);
            }
        }

        return ans;
    }
};

// a = 21  10101
// b = 2   00010
// setbits cnt in b = 1 
//        a = 10101
//       ans= 10000  -> 16 
//     xor =  00001  
// ans = 16

// a = 21  10101
// b = 30  11110 

// st bit cnt in b = 4 
//      a = 10101
//   ans=   10101  , canceling all set bits by seting bits in ans 
//   xor=   00000   , but cnt remiang is 1

// so to setlle remaing cnt we need to set some bits 
// ans = 10101
// set bits from lowest 
// ans = 10111



class Solution {
public:
    
	// O(logn)
    int countSetBits(int n){
        int c=0;
        while(n>0){
            int rmsb=n&(-n); // rightmost set bit
            n-=rmsb;
            c++;
        }
        return c;
    }
    
    int minimizeXor(int num1, int num2) {
        int c=countSetBits(num2);
        
        int x=0; // building answer by nullifying MSB's of 'num1' for 'Overall Minimum XOR'
        for(int bit=31;bit>=0;bit--){
            if((num1 & (1<<bit))>0 && c>0){
                x |= (1<<bit);
                c--;
            }
        }
        
	   // setting LSB's of 'x' so that 'count of set bits are same as num2' & keeping value of 'x' as minimum possible 
        for(int bit=0;bit<=31;bit++){
            if(c>0 && (x & (1<<bit))==0){
                x |= (1<<bit);
                c--;
            }
        }
        return x;
    }
};




int main(){
    Solution sol;
    return 0;
}