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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}

class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n= arr.size();
        int ans =0;
        for(int i=0;i<k;i++){
            vector<int> newArr;
            for(int j=i;j<n;j+=k){
                newArr.push_back(arr[j]);
            }
            ans += newArr.size()-lis(newArr);
        }
        return ans;
    }
    int lis(vector<int>& nums){
        int n=nums.size();
        vector<int> dp;
        for(auto x: nums){
            auto it = upper_bound(dp.begin(),dp.end(),x);
            if(it==dp.end())
                dp.push_back(x);
            else 
                *it=x;
        }
        return dp.size();
    }
};

int main(){
    Solution sol;
    vector<int> arr={4,1,5,2,6,2};
    int k=2;
    int ans = sol.kIncreasing(arr,k);
    cout<<ans;
   return 0;
}