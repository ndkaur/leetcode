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
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long ans = 0;
        int last = INT_MAX;

        for(int i=0; i<n; i++){
            ans += abs(nums1[i]-nums2[i]);
            int end_elm = nums2.back();
            // if the last elem already made then only 1 operation to add into array 
            // last elem in range [min(num1, num2), max(num1, num2)] 
            if(min(nums1[i], nums2[i])<=end_elm && end_elm<=max(nums1[i], nums2[i])){
                last =1; // lies in range , 1 operation to insert
            }
            // if last_elm is not made itlsef while making other elmts then we 
            // have choice to make it from nums1, or nums2, cause in the end nums2 elem are going to be in the nums1 
            // and 1 + because 1 operation to add value in array 
            last = min(last, 1+min(abs(nums1[i]-end_elm), abs(nums2[i]-end_elm)));
        }

        ans+=last;
        return ans;
    }
};

// we can add 1 or subtract 1 , so the basic operation of each nums1-nums2 will always be performned 
// now main situation is how to make the last elemt 
// what if while making other e lmts that elmt gets made , adn to insert it in nums1 we will need 1 operation 
// but the ladt num will lie in range [min(num1, num2), max(num1, num2)] 
// we have to check each possible value at i to see if its equal to last elemt 


int main(){

    return 0;
}