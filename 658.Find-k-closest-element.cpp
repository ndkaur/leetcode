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


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
        int left=0;
        int right=n-k;
        while(left<right){
            int mid=(left+right)/2;
            if(x-arr[mid]>arr[mid+k]-x){
                left= mid+1;
            }
            else 
                right=mid;
        }
        for(int i=left;i<left+k;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};


int main(){
    Solution sol;
    vector<int> arr={1,2,3,4,5};
    int k =4;
    int x=-1;
    vector<int> ans = sol.findClosestElements(arr,k,x);
    print(ans);
    return 0;
}