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
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long sum1 = 0;
        for(int i=0; i<arr.size(); i++){
            sum1 += abs(arr[i]-brr[i]);
        }
        long long sum2 =k;

        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());
        
        for(int i=0; i<arr.size(); i++){
            sum2 += abs(arr[i]-brr[i]);
        }
        long long ans = min(sum1, sum2);
        return ans;
    }
};

int main(){

    return 0;
}