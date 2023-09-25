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
    long long maximumSumOfHeights(vector<int>& heights) {
        // find min from both sides of curr element 
        int n = heights.size();
        long long ans =0;
        for(int i=0; i<n; i++){
            long long sum = heights[i];
            long long last = heights[i];
            // left side of the curr elem
            for(int j=i-1; j>=0; j--){
                last = min((long long)heights[j], last);
                sum += last; 
            }
            // now checking the right side elements of the curr element
            last = heights[i];
            for(int j=i+1; j<n; j++){
                last = min((long long)heights[j], last);
                sum +=  last;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};

int main(){

    return 0;
}