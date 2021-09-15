/*
 * @lc app=leetcode id=1686 lang=cpp
 *
 * [1686] Stone Game VI
 */
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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}

// @lc code=start
class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n= a.size();
        vector<vector<int>> store(n);
        for(int i=0;i<n;i++){ // making pair of tsum and index
            store[i]= {-a[i]-b[i],i}; // -ve so that sort is in decending order 
        }
        sort(store.begin(),store.end());
        int asum=0,bsum=0;
        int aliceTurn=1;
        for(auto x:store){
            if(aliceTurn==1)
                asum+= a[x[1]];
            else 
                bsum+= b[x[1]];
            aliceTurn =1-aliceTurn;
        }
        if(asum>bsum) return 1;
        if(asum==bsum) return 0;
        return -1;
    }
}; 

// (-3,0) (-10,1) (-10,2) 
//  sort  then check the index then go to that index value in a and b 7
// @lc code=end


int main(){
    Solution sol;
    vector<int> a={1,3};
    vector<int> b={2,1};
    int ans = sol.stoneGameVI(a,b);
    cout<<ans;
    return 0;
}