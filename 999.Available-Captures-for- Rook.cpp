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
    int numRookCaptures(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='R'){
                    //up
                    for(int up=i; up>=0; up--){
                        if(board[up][j]=='B')
                            break;
                        else if(board[up][j]=='p'){
                            cnt++;
                            break;
                        }
                    }

                    // down 
                    for(int down=i; down<n; down++){
                        if(board[down][j]=='B')
                            break;
                        else if(board[down][j]=='p'){
                            cnt++;
                            break;
                        }
                    }

                    // left
                    for(int left=j; left>=0; left--){
                        if(board[i][left]=='B')
                            break;
                        else if(board[i][left]=='p'){
                            cnt++;
                            break;
                        }
                    }

                    // right 
                    for(int right=j; right<m; right++){
                        if(board[i][right]=='B')
                            break;
                        else if(board[i][right]=='p'){
                            cnt++;
                            break;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};

int main(){

    return 0;
}