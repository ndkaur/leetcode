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
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        // trick here is that same diagonal elemts have same sum of i +j
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,vector<int>> mp; 
        int mx = 0; // to check total no of diagonals

        for(int i=0; i<n; i++){
            for(int j=0; j<nums[i].size(); j++){
                mp[i+j].push_back(nums[i][j]);
                mx = max(mx, i+j); // keep count of the last value of the diagonal present 
            }
        }
        // diag = 0 {1} 
        // diag = 1 {2,4}
        // diag = 2 {3,5,7}
        // but the ans is in rev order 
        // {1,4,2,7,5,3,8,6,9}
        for(int i=0; i<=mx; i++){
            // reverse order insertion 
            for(auto x = mp[i].rbegin(); x!=mp[i].rend(); x++){
                // reference is to need to take the element present at that address 
                ans.push_back(*x);
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}