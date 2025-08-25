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
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int mod = 1e9+7;
        vector<int> ans;
        vector<int> pow;
        for(int i=0; i<32; i++){
            if((n & (1<<i))!=0){// set bit 
                pow.push_back(1<<i);
            }
        }

        for(auto q:queries){
            int i = q[0];
            long product = pow[i++];
            while(i<=q[1]){
                product = (product*pow[i])%mod;
                i++;
            }
            ans.push_back(product);
        }
        return ans;
    }
};

// we have to make power array 
// 2^0 + 2^1 + 2^2 + 2^3 = 15 
// {1, 2, 4, 8} = sum of all is 15
// whoch we see is binary represntation of 15 = 1111 
// 12 -> 1100 = 2^2 + 2^3= 4+8 =12
// in that powers array take the product

int main(){

    return 0;
}