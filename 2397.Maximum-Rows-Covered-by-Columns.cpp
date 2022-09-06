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
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int cnt =0; 
        vector<bool> visited(mat[0].size(), false);
        int ans = INT_MIN;
        f(0, cols, mat, cnt, visited, ans);
        return ans;
    }
    void f(int idx, int cols, vector<vector<int>> & mat, int cnt, vector<bool>& visited, int& ans){
        int n= mat.size();
        int m= mat[0].size();
        if(idx==m || cols==0){
            int count = 0;
            for(int i=0; i<n; i++){
                bool flag = true;
                for(int j=0; j<m; j++){
                    // if it is 1 and not visited
                    if(mat[i][j] == 1 && visited[j]==false){
                            flag= false;
                            break;
                    }
                }
                if(flag)
                    count++;
            }
            ans = max(ans,count);
            return;
        }

        // general code of backtracking format
        visited[idx]= true;
        f(idx+1, cols-1, mat, cnt+1, visited, ans); // pick
        visited[idx] = false; // backtrack
        // not pick 
        f(idx+1, cols, mat, cnt, visited, ans);
        return;
    }
};

// we have to choose the columns equal to cols val 
// for each column choosen we have to check all rows of it 
// see if any one is not covered in that row by the selected cols 


int main(){

    return 0;
}