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
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        if(k == 0){ // if k 0 nothing can be added or subtrated 
            if(nums1 == nums2)
                return 0;
            return -1;
        }

        long long  pos = 0;
        long long neg = 0;
        for(int i=0; i<n; i++){
            if(nums1[i] >= nums2[i]){
                pos += (nums1[i] - nums2[i]);
            }
            else{
                neg += (nums2[i] - nums1[i]);
            }
        }
        long long  ans = -1;
        // if both pos and neg are equal that means we can calculate both at same time to make the array equal
        // and is pos is exactly divisible by k that means we can find the eaxct number of operations 
        if((pos - neg == 0) && (pos % k == 0))
            ans = pos/k; // number of operations -> 1 operation is -> adding k , subtracting k 
        return ans;
    }
};


class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        // we can make n1 equal to n2 only if the diffrence of both is a facor of k 
        // if it is a factor then we can add/ subtract k in n1 to make it n2 
        long long inc = 0;
        long long dec = 0;
        for(int i =0; i<n; i++){
            if(nums1[i] != nums2[i]){
                // if the diff is not a factor of k then answer not possible 
                if(k==0 || abs(nums1[i]- nums2[i]) % k != 0)
                    return -1;
                // inc -> nums1[i] < nums2[i] -> nums+k
                inc += max(0, (nums2[i] - nums1[i]) / k);
                // dec -> nums1[i] > nums2[i] -> nums- k
                dec += max(0 , (nums1[i] - nums2[i]) / k);
            }
        }
        return inc != dec ? -1 : inc;
    }
};




int main(){

    return 0;
}