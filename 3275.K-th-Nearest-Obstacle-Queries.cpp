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


class Solution { // nlogk
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int n = queries.size();
      
        vector<int> ans(n);
        priority_queue<int> pq;
       
        for(int i=0; i<n; i++){
            int dist = abs(queries[i][0])+abs(queries[i][1]);
            pq.push(dist);

            if(i<k-1){
                ans[i]=-1;
            } 
            else{
                if(pq.size()>k){
                    pq.pop();
                }
                int val = pq.top();
                ans[i] = val;
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}