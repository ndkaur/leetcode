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
    long long minOperations(vector<vector<int>>& queries) {
        int n = queries.size();
        long long ans = 0;
        for(int i=0; i<n; i++){
            // specifing the range
            long long start = queries[i][0];
            long long end = queries[i][1];

            long long operations=0;
            // iterting the powers of 4 ranges 
            long long prev = 1;
            for(long long p=1; p<17; p++){
                // 1*4= 4(1,4)   4*4= 16 (4, 16-1)
                long long curr = prev * 4LL;
                long long left = max(start, prev);
                long long right = min(end, curr-1);

                if(right>=left)
                    operations += (right-left+1)*p; // many smae elemts can repeat          
                prev= curr;
            }
            ans+= (operations+1)/2;
        }
        return ans;
    }
};

// so ranging it with powers of 4 
// 1,2,3 -> need 1 operation (1-> 4^1-1)
// 4,5,6,7,8..15 -> need 2 operations (4, 16-1)
// 16, 17, 18 ...63 -> need 3 operations  (16, 64-1) 


int main(){

    return 0;
}