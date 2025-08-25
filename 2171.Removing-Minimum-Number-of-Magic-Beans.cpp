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
    long long minimumRemoval(vector<int>& beans) {
        long long n = beans.size();
        long long tsum = 0;
        for(int bean:beans){
            tsum+=bean;
        }
        long long mn = LLONG_MAX;
        sort(beans.begin(), beans.end());
        // tsum - (n-idx)*(currval)
        for(int i=0; i<n; i++){
            mn = min(mn, tsum - (n-i)*beans[i]);
        }
        return mn;
    }
};

// we need to makethe arry equal to any one elem so that it takes min operations
// and if we sort the array then if we makeing num greeter that val at current index we can simply drop that val number of beans 
// 4 1 6 5
// sort -> 1 4 5 6
// if we make 1 then total no of drops of beans ->
// 0 + (4-1) + (5-1) + (6-1) = 0+3+4+5 =12
// if we make equal to 4
// 1 + 0 + 5-4 + 6-4 = 1+0+1+2=4

// a b c d 
// drops for a -> 0 + (b-a) + (c-a)+ (d-a) = b+c+d -3a = a+b+c+d -4a = tsum-4a
//drops for b-> a + 0+ (c-b)+(d-b)= a+c+d-2b = a+b+c+d-3b = tsum-3b
// drops for c-> a+b+0+(d-c) = a+b+d-c= a+b+c+d-2c = tsum-2c
// drops for d-> a+b+c+0 = a+b+c+d-d= tsum-d

// standart formula = tsum - (n-idx)*(currval)
// 1 4 5 6 
// moves for 4 = 16-3*4 = 16-12= 4


int main(){

    return 0;
}