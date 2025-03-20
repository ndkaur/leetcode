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
        vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
            int n = nums.size();
            map<int,vector<int>> mp;
            for(int i=0; i<n; i++){
                mp[nums[i]].push_back(i);
            }
    
            vector<int> ans(queries.size(), -1);
            for(int i=0; i<queries.size(); i++){
                int idx = queries[i];
                int val = nums[idx];
    
                int sz = mp[val].size();
                if(sz==1)
                    continue;
                
                // lb is >=val
                // it return the equal value
                int pos = lower_bound(mp[val].begin(), mp[val].end(), idx) - mp[val].begin();
                // l can go to neg eg-> pos=0, 0-1 =-1%sz not possible 
                // so we add sz to make it again +ve , -1+2(sz) =  1%2=1
                // cout<<pos<<endl;
                // for this pos we find the left and right idx 
                // left is in circular way , right is next val
                int l = (pos-1+sz)%sz;
                int r = (pos+1)%sz;
                // 1->{0,2,4} pos = 0, left = 2idx , right = 1idx
                // possiblities -> 0->2, 0->4 
                // in circular way  -> 2->0, 4->0 (n-i)
                int diff_left = abs(idx-mp[val][l]);
                int diff_right = abs(idx-mp[val][r]);
    
                diff_left = min(diff_left, n-diff_left);
                diff_right = min(diff_right, n-diff_right);
    
                ans[i] = min(diff_left, diff_right);
            }
            return ans;
        }
    };
    
    // nums = [1,3,1,4,1,3,2], queries = [0,3,5]
    // 1 -> {0,2,4}
    // 3 ->  {1,5}
    // 4 ->  {3}
    // 2 -> {6}


int main(){

    return 0;
}