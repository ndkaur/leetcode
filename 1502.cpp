#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
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
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int diff=arr[0]-arr[1];
        for(int i=0;i<n-1;i++){
            if(arr[i]-arr[i+1]!=diff) 
                return false;
        }
        return true;
    }
};


int main(){
    Solution sol;
    vector<int> arr={1,2,4};
    bool ans=sol.canMakeArithmeticProgression(arr);
    cout<<ans;
    return 0;
}