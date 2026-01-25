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
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        long long sum =0;
        int neg_cnt = 0;
        int neg_min = INT_MAX;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                sum+= abs(matrix[i][j]);
                if(matrix[i][j]<0){
                    neg_cnt++;
                }
                neg_min = min(neg_min, abs(matrix[i][j]));
            }
        }
        if(neg_cnt%2!=0){
            // wehen taking sum we have added each number, and if odd negative sign is remining that means we have to remove that number once + we have also added it once in begining so 2 times 
            sum = sum-2*neg_min;
        }
        return sum;
    }
};


int main(){

    return 0;
}