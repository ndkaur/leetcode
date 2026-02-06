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
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        int  mx_size = 0;
        sort(nums.begin(), nums.end());
        int l =0;
        int r = 0;
        while(r<n){
            while(l<=r && (long long)nums[r]>(long long)nums[l]*k){
                l++;
            }
            if(r-l+1>mx_size){
                mx_size = r-l+1;
            }
            r++;
        }
        return n-mx_size;
    }
};


// cant use priority_queue as we cant fix the min value to be removed, 
// eg-> [ 1,34,23] cnt = 1, balance arry = [34,23]


int main(){

    return 0;
}