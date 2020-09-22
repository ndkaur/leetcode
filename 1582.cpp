#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
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
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        map<int,int> r,c;
        for(int i=0;i<m;i++){
            int t=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1)
                    t++;
            }
            if(t==1)
                r[i]++;
        }

        for(int j=0;j<n;j++){
            int t=0;
            for(int i=0;i<m;i++){
                if(mat[i][j]==1)
                    t++;
            }
            if(t==1)
                c[j]++;
        }
        
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] && r[i] && c[j])
                    count++;
            }
        }
        return count;
    }
};


int main(){
    Solution sol;
    vector<vector<int>> mat={{1,0,0},{0,0,1},{1,0,0}};
    int count=sol.numSpecial(mat);
    cout<<count;
    return 0;
}