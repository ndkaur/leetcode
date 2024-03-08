/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 */
#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) int((a).size())
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7;
template<class T, class U> inline void addSelf(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void minSelf(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void maxSelf(T &x, U y) { if (y > x) x = y; }


// @lc code=start
class Solution0 {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // int len =grid.size();
        int negcount =0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]<0)
                  negcount ++;
                }  
        }
        return negcount;
    }
};

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        // sorted in decreasing order 
        int i = 0;
        int j = m-1;
        while(i<n && j>=0){
            // if curr elm negative then its whole column will be negative as its decreasing order if most greater elem is -ve reast will also be -ve , then change column idx 
            if(grid[i][j]<0){
                cnt += (n-i); 
                j--;
            }
            else if(grid[i][j]>=0){ // curr elem +ve then we not sure if remaing elem int hat column will be -ve or not so change row 
                i++;
            }
        }
        return cnt;
    }
};


class Solution { //O(nlogm)
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int cnt=0;
      
        for(int i=0; i<n; i++){
            int l=-1;
            int r= m;
    
            while(1+l<r){
                int mid= l+(r-l)/2;
                if(grid[i][mid]<0){
                    r= mid;
                }
                else{
                    l=mid;
                }
            }
            //  the l will be at the last +ve no
            // the r will be at the first -ve no
            cnt+= m-r;
            
        }
        return cnt;
    }
};


// @lc code=end  


int main(){
    Solution sol;
    vector<vector<int>> grid;
    int i,j,negcount;
    grid={{ 4, 3, 2,-1},
          {-3,-2,-1,-1}};
    negcount=sol.countNegatives(grid);
    cout<<negcount;
    return 0;
}