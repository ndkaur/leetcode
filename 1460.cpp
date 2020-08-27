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
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int m=target.size();
        int n=arr.size();
        if(m!=n){
            return false;
        }
        else{
            sort(target.begin(),target.end());
            sort(arr.begin(),arr.end());
        }
        return(target==arr);        
    }
};


int main(){
    Solution sol;
    vector<int> target={3,7};
    vector<int> arr={3};
    bool ans=sol.canBeEqual(target,arr);
    cout<<ans;
    return 0;
}