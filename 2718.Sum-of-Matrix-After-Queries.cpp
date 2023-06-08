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

// runtime error
class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        int sz = queries.size();
        for(auto query:queries){
            if(query[0]==0){
                int i = query[1];
                int val = query[2];
                for(int j=0; j<n; j++){
                    queries[i][j] = val;
                }
            }
            if(query[0]==1){
                int j = query[1];
                int val = query[2];
                for(int i=0; i<n; i++){
                    queries[i][j]=val;
                }
            }
        }

        int sum =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                sum += queries[i][j];
            }
        }
        return sum;
    }
};


class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        int sz = queries.size();
        vector<bool> row(n,1);
        vector<bool> col(n,1);
        long long  r=n;
        long long  c=n;
        long long ans =0;
        for(int i=sz-1; i>=0; i--){
            // if 0 or 1 and is not visited
            if(queries[i][0]==0 && row[queries[i][1]]){ // row but in actual col get effected
                ans += c*queries[i][2];
                r--;
                row[queries[i][1]]=0;
            }
            if(queries[i][0]==1 && col[queries[i][1]]){// col  but in actual row get effected
                ans += r*queries[i][2];
                c--;
                col[queries[i][1]]=0;
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}