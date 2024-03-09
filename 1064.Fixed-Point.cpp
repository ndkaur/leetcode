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

class Solution0 {
public:
    int fixedPoint(vector<int>& arr) {
        int n = arr.size();
        int ans=-1 ;
        for(int i=0; i<n; i++){
            if(arr[i]==i){
                ans = i;
                break;
            }
        }
        return ans==n ? -1: ans;
    }
};


class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int n = arr.size();
        int l = 0;
        int r =  n-1;
        int ans= -1 ;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(arr[mid]==mid){
                ans = mid;
            }
            if(arr[mid]<mid){
                l = mid+1;
            }
            else 
                r = mid-1;
        }
        return ans;
    }
};



int main(){

    return 0;
}