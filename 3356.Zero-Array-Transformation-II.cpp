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


// / O(n∗log(m)), time 

// Space Complexity: O(n)


class Solution {
    public:
        bool check(int midsz, vector<vector<int>>& queries, vector<int>& nums){
            vector<int> prefix_arr(nums.size()+1,0);
            
            for(int i=0; i<midsz; i++){
                int start = queries[i][0];
                int end = queries[i][1];
                int val = queries[i][2];
    
                prefix_arr[start] +=val;
    
                if(end+1<nums.size())
                    prefix_arr[end+1]-=val;
            }
            int sum =0;
            for(int i=0; i<nums.size(); i++){
                sum += prefix_arr[i];
                // if prefix sum is greater that means it is true
                if(sum<nums[i])
                    return false;
            }
            return true;
        }
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n = nums.size();
            int m = queries.size();
           
            // now find how may queries we will take 
            int l =0;
            int r =m;
            int ans = -1;
            while(l<=r){
                int mid = l+(r-l)/2;
                if(check(mid, queries, nums)){// true
                    ans = mid;
                    r = mid-1;
                }
                else{ // false then increase queries
                    l = mid+1;
                }
            }
            return ans;
        }
    };
    
    
    
    // prefix sum and binary search concept
    // we need to check if after applying all queries is there any number that doent becomes 0
    // for this we use prefix sum
    // aftere this if we know that all nums can become 0 then we have to find that how many 
    // queries we need? 
    // if we check for each query linearly then it will take time
    // so we do binary search and find if we take 1 wueriy is it possible , if not then take more and so on 

int main(){

    return 0;
}