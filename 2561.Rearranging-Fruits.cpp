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
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int,int> mp;
        for(int b:basket1){
            mp[b]++;
        }
        for(int b:basket2){
            mp[b]--;
        }
        vector<long long> freq;
        long long ans = 0;

        long long mn=LLONG_MAX;

        for(auto itr:mp){
            mn = min(mn, (long long)itr.first);
            if(itr.second%2!=0) // odd
                return -1;
            // no of time that occur/2 -> fre1/2 time inset in array
            for(int i=0; i<abs(itr.second)/2; i++){
                freq.push_back(itr.first);
            }
        }

        sort(freq.begin(), freq.end());
        for(int i=0; i<freq.size()/2; i++){
            ans+= min(mn*2, freq[i]);
        }
        return ans;
       
    }
};
// observations
// 1) those numbers with odd freq can never be swaped so -1 
// 2) when num in arr1 increse cnt , when num in arr2 decre cnt , when alredy present reduce alredy occuring cnt 
// 3) in the freq array when we swap 2 nums it makes 2 pairs in correct condition
// 4) so we make freq array and add half of the freq of the nums cause only that will be added 
// 5) when the array is sorted , we will take the minium values upto half the freq array size 
// but if we have a minimum value then we can keep on swaping it up and down to balance the array, cause we can use any num to swap and balance out 
// so 2 swaps of min number can balance out 2 pairs, each pair from both arrays 

// so when calculating total ans we will see if (2*min, num), which is minimum we will take it ;

// num1 = 2,2,3,3,4,5
// num2 = 4,5,6,6,7,7   
// min val = 2 
// freq arr = 2,3,6,7
// we will take half of fre arr
// min(2*2, 2) = 2 
// min(2*2, 3) = 3   -> 2+3 =5


//basket1 = [84,80,43,8,80,88,43,14,100,88]
// basket2 = [32,32,42,68,68,100,42,84,14,8]
// min val = 8 
// freq = 80, 43, 88, 32, 42, 68 
// sorted freq = 32, 42, 43, 68, 80, 88 
// we will take half 
// ans  = min(8*8 , 32) = 16 
// ans = 16 + min(8*8, 42)= 16+16 = 32
// ans = 32 + min(8*8, 43) =32+16 =  48



int main(){

    return 0;
}