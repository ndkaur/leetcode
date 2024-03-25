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
    int minOperations(int k) {
        int cnt = INT_MAX;
        // we already have i , now we want to duplicate it so cnt operations to dulpicate it ie k/i
        for(int i=1; i<=k; i++){
            int temp = ceil(k/(i*1.0));
            cnt = min(cnt, i-2+temp);
        }
        return cnt;
    }
};



class Solution {
public:
    int minOperations(int k) {
        int mn = k-1;
        // we already have i , now we want to duplicate it so cnt operations to dulpicate it ie k/i
        for(int i=(k+1)/2; i>=1; i--){
            int increase = i-1;
            //ceil(n,k) = (n+k-1)/k
            int duplicate = ((k+i-1)/i)-1; // finding the ceil formula
            int total = increase + duplicate;
            mn = min(mn, total);
        }
        return mn;
    }
};



// k/i
//10/2 = 5 
// 2-2+5 = 5
// i=3  10/3 = 3 , 4-2+3 = 5

// so start iteration k=11
// i=1,  10 operations 
//operations + groups
// i=2, 1 + (11/2)= 1+5 = 6  .... 1 operation to make 1->2
// i=3, 2 + (11/3)= 2+3 = 5 ... 2 operations to make 1->2->3 
//i=4, 3 + (11/4) = 3 + 2 = 5

// so if we observe the min is = operations-1 + groups-1 



int main(){

    return 0;
}