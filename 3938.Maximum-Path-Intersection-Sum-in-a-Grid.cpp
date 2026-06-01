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



class Solution { //O(n*m)
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = INT_MIN;
        for(int i=0; i<n; i++){ // row kadane
            int ongoing_sum = grid[i][0]; 
            for(int j=1; j<m; j++){
                int curr_sum = ongoing_sum + grid[i][j];
                ans = max(ans,curr_sum);
                if(i>0 && i<n-1 && j>0 && j<m-1){ // non corner elem 
                    ans = max(ans, grid[i][j]);
                }
                ongoing_sum = max(grid[i][j], curr_sum);
            }
        }

        // column kadane
        for(int j=0; j<m; j++){
            int ongoing_sum = grid[0][j];
            for(int i=1; i<n; i++){
                int curr_sum = ongoing_sum + grid[i][j];
                ans = max(ans, curr_sum);
                // not a corner elem 
                if(i>0 && i<n-1 && j>0 && j<m-1){
                    ans = max(ans, grid[i][j]);
                }
                ongoing_sum = max(curr_sum, grid[i][j]);
            }
        }
        return ans;
    }   
};

// so baiscally ques is 
// corner elem can tbe taken alone
// rest we cna take a single commnon elem other that boundary
// comomon can be either row sum or col sum cause bth move in diff direct
// so we take pref sum of row wise and col wise, 
// we have ngative lem so kadene 

// kadane -> max(ongoing_sum+ curr_elm, cur_elm)



int main(){

    return 0;
}