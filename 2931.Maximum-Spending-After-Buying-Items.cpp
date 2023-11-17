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
    long long maxSpending(vector<vector<int>>& values) {
        int n = values.size();
        int m = values[0].size();
        // min heap
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>> , greater<pair<int, pair<int,int>>>>pq;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                pq.push({values[i][j], {i,j}});
            }
        }

        long long d = 1;
        long long sum =0;
        while(pq.size()){
            sum += pq.top().first * d;
            pq.pop();
            d++;
        }
        return sum;
    }
};

int main(){

    return 0;
}