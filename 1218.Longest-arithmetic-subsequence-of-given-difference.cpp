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

// arr ={1,2,3,4} dif= 1 ans=4
// arr={1,3,5,7} dif=1 ans=1
//arr ={1,5,7,8,5,3,4,2,1} diff= -2 ans =4

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int n= arr.size();
        int ans=1;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]] = mp[arr[i]-diff]+1;
            ans= max(ans,mp[arr[i]]);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> arr={1,5,7,8,5,3,4,2,1};
    int diff= -2;
    int ans =sol.longestSubsequence(arr,diff);
    cout<<ans;
    return 0;
}