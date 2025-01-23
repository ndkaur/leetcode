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



class Solution0 { // tle
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int temp = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int val = nums1[i] ^ nums2[j];
                temp = temp^val;
            }
        }
        return temp;
    }
};


// if the nums1 array is even length then all will gets canceled out 
// 1) nums1 -> even    ans = 0
//    nums2 -> even 

// 2) nums1-> odd
//   nums2 -> odd    ans = zor of all nums of nums1 and nums2

// 3) nums1 -> even  ans = xor of all nums of num1
//   nums2 ->  odd    

// 4) nums1-> odd
//  nums2 -> even   ans = zor of all nums of nums2 

// the arrays thats odd its ans depend on ecen length array 

class Solution { 
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        int a1, a2 = 0;

        if(n%2==1){ // odd length of nums1 then its ans depend on nums2
            for(int num:nums2){
                a1 = a1^num;
            }
        }
        if(m%2==1){ // odd length of nums2 then its answer depend on nums1
            for(int num:nums1){
                a2 = a2^num;
            }
        }
        // odd,odd -> both arrays in ans
        // even , even -> no if will work ans =0
        // even, odd -> 
        return a1^a2;
    }
};

int main(){

    return 0;
}