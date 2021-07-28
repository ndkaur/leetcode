#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

class Solution0 {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n= arr.size();
        int ans=0;
        int cur_max=0;
        int m= 1e9 +7;
        for(int i=0;i<k;i++){
            for(int n:arr){
                cur_max = max(cur_max + n ,n) % m;
                ans = max(ans, cur_max) % m;
            }
        }
        return ans;
    }
};


class Solution {
public:
    long long  m= 1e9 +7;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n= arr.size();
        int ans =0;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        if(k==1)
            ans = (kadenOne(arr,n))%m;
        else if(sum >0)
            ans = (kadenTwo(arr,n) + ((k-2) * sum ))%m;
        else 
            ans = (kadenTwo(arr,n))%m;
        if(ans <0) return 0;
        return ans %m;
    }
    int kadenOne(vector<int>&arr, int n){
        int res = arr[0];
        int curr= arr[0];
        for(int i=1;i<n;i++){
            curr = max(arr[i],arr[i]+curr);
            res = max(res, curr);
        }
        return res; 
    }

    int kadenTwo(vector<int>&arr, int n){
        int ans = arr[0];
        int curr = arr[0];
        for(int i=1;i<2*n;i++){
            curr = max(arr[i % n],arr[i % n]+curr);
            ans = max(ans, curr);
        }
        return ans;
    }
};



int main(){
    Solution sol;
    vector<int> arr={1,2};
    int k =1;
    int ans =sol.kConcatenationMaxSum(arr,k);
    cout<<ans;
    return 0;
}