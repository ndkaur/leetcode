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
    int minSetSize(vector<int>& arr){
        int n = arr.size();
        vector<int> v;
        sort(arr.begin(),arr.end());
        int count=1;
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1])  
                count++;
            else{
                v.push_back(count);
                count=1;
            }
        } // counted the occurence of each element
        v.push_back(count);
        sort(v.begin(),v.end());
        int sz=n/2;
        int ans =0;
        for(int i=v.size()-1; i>=0 && sz>0;i--){
            ans++;
            sz=sz-v[i];
        } // move from behind and remove ele till not grater than or equal to half
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> arr ={7,7,7,7,7};
    int ans = sol.minSetSize(arr);
    cout<<ans;
    return 0;
}