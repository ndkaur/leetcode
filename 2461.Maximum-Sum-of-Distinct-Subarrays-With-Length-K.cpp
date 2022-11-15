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

        // 0 1 2 3 4 5 6  
// nums = [1,5,4,2,9,9,9], k = 3

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> st;
        int  j=0;
        int i=0;
        long long sum =0;
        long long mx=0;
        while(i < n-k+1){
            if(j-i  == k){                                                                                         
                mx = max(mx, sum);
                // removing ith num
                sum = sum - nums[i];
                st.erase(nums[i]);
                i++;
            }
            else if(st.find(nums[j]) == st.end()){
                sum+= nums[j];
                st.insert(nums[j]);
                j++;
            }
            else{ // alredy in set  remove i num 
                sum = sum - nums[i];
                st.erase(nums[i]);
                i++;
            }
        }
        return mx;
    }
};


int main(){

    return 0;
}