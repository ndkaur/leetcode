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

class Solution { // time = O(NLogN+MLogM)   space = O(N+M)
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& profit, vector<int>& worker) {
        int n= profit.size();
        vector<pair<int,int>> arr;
        for(int i=0; i<n; i++){
            arr.push_back({diff[i], profit[i]});
        }
        sort(arr.begin(), arr.end());
        sort(worker.begin(), worker.end());

        int i=0;
        int ans =0;
        int cur =0;

        // for each worker we are finding in the array the diff that is less or equal to the curr workers diff level given 
        for(int work:worker){
            while(i<n && work>=arr[i].first){ // atmost 
            // 2, 4 both valid so we take max of both 
                cur = max(cur, arr[i].second);
                i++;
            }
            ans += cur;
        }
        return ans;
    }
};

int main(){

    return 0;
}