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
    int find(vector<int>& nums, int target){ // method used to find if equal to target in a 1d array 
        unordered_map<int,int>mp;
        mp[0]=1;
        int curr=0;
        int ans =0;

        for(auto val:nums){
            curr += val;
            if(mp.find(curr-target)!=mp.end()){ // diff found
                ans+= mp[curr-target];
            }
            mp[curr]++;
        }
        return ans;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;
        for(int i=0; i<n; i++){
            vector<int> sumarr(m, 0); // to store the prefix sum col wise for each row  
            for(int j=i; j<n; j++){ // row
                for(int k=0; k<m; k++){ // col
                    sumarr[k] += matrix[j][k];
                }
                ans += find(sumarr, target);
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}