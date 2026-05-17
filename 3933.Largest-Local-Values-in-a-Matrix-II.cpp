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


class Solution { //O((n*m)^2)
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<pair<int,int>>> pos(201);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                pos[matrix[i][j]].push_back({i,j});
            }
        }

        int ans = 0;
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                int val = matrix[row][col];
                if(val==0)
                    continue;
                bool check = true;
                // we start will val+1, and check if new max val exist in pos, iterate its pair and if its withing the square range , make the bool false
                for(int v=val+1; v<=200; v++){ 
                    for(auto p:pos[v]){
                        int new_row = abs(p.first-row);
                        int new_col = abs(p.second-col);

                        if(new_row<=val && new_col<=val){ // valid idx ie int he sqaure
                            if(new_row==val && new_col==val){ // if a corenr value ignore it 
                                continue;
                            }
                            check = false;
                            break;
                        }
                    }
                }
                if(check)
                    ans++;
            }
        }
        return ans;
    }
};

// storing the pairs which all have non zero values
// then iterating over those pairs, finding if they are within the row+x, row-x, col+x, col-x range, if so and not corner then increase the cnt



int main(){

    return 0;
}