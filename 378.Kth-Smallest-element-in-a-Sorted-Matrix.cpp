#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
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
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++)
                pq.push(matrix[i][j]);
        }
        while(pq.size() !=k){
            pq.pop();
        }
        return pq.top();
    } 
};

int main(){
    Solution sol;
    vector<vector<int>> matrix={{1,5,9},{10,11,13},{12,3,15}};
    int k=8;
    int ans = sol.kthSmallest(matrix,k);
    cout<<ans;
    return 0;
}