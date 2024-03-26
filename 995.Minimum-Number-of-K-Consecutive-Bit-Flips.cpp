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


class Solution0 {  // tle ->O(n*k)
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                if(i+k-1>=n)
                    return -1;
                for(int j=i; j<i+k; j++){
                    nums[j]=!nums[j];
                }
                cnt++;
            }
        }   
        return cnt;
    }
};


// kind of sliding window 
// so the trick is keep a track of nums using prefix array 
// and flip the bit prefix no of times , if its still one move to next idx
// if its 0 then take a window of k size and at k+1 mark -1 
// this will heap us know that k window is done and cnt++ and now new window must start but if the start of new window is 1 we move ahead 
// if the start of new window is 0 then we again repaet the same process and make a window of size k and solve for the same 

// fliping the bit observations
// num = 0 , flips = odd = 3  -> 0 1 0 1 = 1 
// num = 0, flips = even = 4  -> 0 1 0 1 0 = 0  , even flips num remain same
// num = 1, flips = even = 4  -> 1 0 1 0 1 = 1 , even flips num remain same
// num = 1, flips = odd = 3   -> 1 0 1 0 = 0  

class Solution {   //O(N)
public:
    int flipBits(int num, int flips){
        if(flips%2==0){ // even flips then num remains the same 
            return num;
        }
        return !num;
    }
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt =0;
        vector<int> prefix(n+1,0); // it store the no of times the curr ith idx has to be fliped 

        // filling the prefix array with the no of times the curr idx will be flipped 
        for(int i=0; i<n; i++){
            if(i!=0){ // we want i-1 th position 
                prefix[i] += prefix[i-1]; 
            }
            // we can go only upto n-k to make k size widow 
            if(i<n-k+1){
                int flips = prefix[i];
                // the resutling num after fliping 
                int num = flipBits(nums[i], flips);
                if(num==1)
                    continue;
                // if num is 0 , increase the cnt
                cnt++;
                prefix[i]++; // marking curr 0 as 1 in prefix array so that we can cnt the total no of ones later
                prefix[i+k]--; // amrking the window 
            }
        }

        // now checking if all nums at the end are 1
        int ones = 0;
        // since we havent fliped in actual array we need to caluclate from prefix array 
        vector<int> temp(n);
        for(int i=0; i<n; i++){
            temp[i] =  flipBits(nums[i], prefix[i]);
            ones += (temp[i]==1);
        }
        return ones==n ? cnt : -1;
    }
};

int main(){

    return 0;
}