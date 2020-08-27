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
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        if(n<2) 
            return false;

        for(int i=0;i<n-2;i++){
            if(arr[i]%2!=0 && arr[i+1]%2!=0 && arr[i+2]%2!=0){
                return true;
            }
        }
    return false;
    }
};

int main(){
    Solution sol;
    vector<int> arr={2,6,4,1};
    bool ans=sol.threeConsecutiveOdds(arr);
    cout<<ans;
    return 0;
}