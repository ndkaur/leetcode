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
        int maxSum(vector<int>& nums) {
            int n = nums.size();
            int mx = INT_MIN;
            set<int> st;
            int sum =0;
            for(int i=0; i<n; i++){
                mx = max(mx, nums[i]);
                if(nums[i]<=0 || st.find(nums[i])!=st.end())
                    continue;
                sum += nums[i];
                st.insert(nums[i]);
            }
            return (mx<=0)?mx:sum;
        }
    };
    
    
    class Solution {
    public:
        int maxSum(vector<int>& nums) {
            int n = nums.size();
            int mx = INT_MIN;
            set<int> st;
            int sum =0;
            for(int i=0; i<n; i++){
                if(nums[i]>0){
                    st.insert(nums[i]);
                }
                else 
                    mx = max(mx, nums[i]);
            }
            for(auto val:st){
                sum +=val;
            }
            if(st.size())
                return sum;
            else 
                return mx;
            
        }
    };
    
    // [2,-10,6] ans = 8

int main(){

    return 0;
}