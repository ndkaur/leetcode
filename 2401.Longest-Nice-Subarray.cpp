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

// if we go with normal sliding window approach 
// we need to calculate & of each num with every other num in the window 
//  eg -> j =3 so 3&48, 8 & 48
// its gonna take O(n^2) time , double for loop
// so need optimization  
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int i = 0;
        int j = 0;
        int ans = 0;

        int orr = 0;

        while(j<n){
            // invalid condition
            while((orr & nums[j])>0){ // the  result of & is not zero
                // remove the ith element by doing zor of it 
                orr = orr ^ nums[i];
                i++;
            }
            // combining the set bits of all te numbers in the window
            // simple way to combine set bits in one number is by doing OR
            orr = orr | nums[j];
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};

//  0 1 2  3  4 
// [1,3,8,48,10]
//  i= 0 , j=0
// orr = 0  ans =0
// orr & nums[0] = 0 & 1 = 0   ans = j-i+1 = 0-0+1 = 1  orr = all set bits  = orr | nums[0]=  0 | 1 =1

//  orr = 1 , ans =1 
//  i=0 , j= 1
//  orr & nums[1] = 1 & 3 = 1 > 0  so we need to shift our window 
//  remove the  nums[i] so do zor =  orr ^ nums[i] = 1 ^ 1 = 0

//  orr = 0 ans =1
//  i=1 j=2
// orr & nums[2] = 0 & 8 = 0  , ans = 2-1+1 = 2  , orr = orr | nums[j] = 0 | 8   = 8

//  orr= 8 , ans =2 
//  i=1 j=3  
// orr & nums[j] = 8 & 48 ==0 , ans = 3-1+1 = 3 , orr= orr | nums[j] = 8 | 48 = 57 

// orr =57  , ans = 3 
//  i=1 , j=4 
// orr & nums[j] = 57 & 10 > 0 .. so change window remove nums[i]
// to remove orr ^ nums[i] = 57 ^ 3 =  some num 

// then again move i 
// ....
//  sinally max ans = 3 

