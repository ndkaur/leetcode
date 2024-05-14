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
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<vector<double>> workers;
        for(int i=0; i<n; i++){
            workers.push_back({(double)(wage[i])/quality[i], (double)quality[i]});
        }

        sort(workers.begin(), workers.end());

        double res = DBL_MAX;
        double qsum = 0;

        priority_queue<int> pq;

        for(auto worker: workers) {
            qsum += worker[1];
            pq.push(worker[1]);
            if(pq.size()>k){
                qsum -= pq.top();
                pq.pop();
            }

            if(pq.size()==k){
                res = min(res, qsum * worker[0]);
            } 
        }
        return res;
    }
};

int main(){

    return 0;
}